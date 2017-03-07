#include "Chrono.h"
namespace Chrono
{
	Date::Date(int yy, Month mm, int dd) :y(yy), m(mm), d(dd)
	{
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
			                    31,29,31,30,31,30,31,31,30,31,30,31 };
		int yd[2] = { 365,366 };
		if (!is_date(yy, mm, dd)) throw Invalid();
		int i;
		since = 0;
		for (i = 1970; i < y; ++i) since += yd[leapyear(i)];
		for (i = 0; i < m - 1; ++i) since += md[leapyear(y)][i];
		since += dd - 1;
	}
	Date& default_date()
	{
		static Date dd(2001, Date::jan, 1);
		return dd;
	}
	Date::Date(long s):since(s)
	{
		Month mmm[12] = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		if (s<0) throw Invalid();
		long tmp = s;
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
			                    31,29,31,30,31,30,31,31,30,31,30,31 };
		int yd[2] = { 365,366 };
		y = 1970; m = jan; d = 1;
		while (s >= yd[leapyear(y)])
		{
			s -= yd[leapyear(y)];
			++y;
		}
		while (s >= md[leapyear(y)][m - 1])
		{
			s -= md[leapyear(y)][m - 1];
			m = mmm[m];
		}
		d += s;
	}
	Date::Date():y(default_date().year()), m(default_date().month()),d(default_date().day()){}
	void Date::add_day(int n)
	{
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
		                        31,29,31,30,31,30,31,31,30,31,30,31 };
		const Month mn[12] = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		d += n;
		while (d > md[leapyear(y)][m - 1])
		{
			d -= md[leapyear(y)][m - 1];
			m = mn[m % 12];
			if (m == jan) ++y;
		}
	}
	void Date::add_month(int n)
	{
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
			                    31,29,31,30,31,30,31,31,30,31,30,31 };
		const Month mn[12] = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		y += (m + n) / 12;
		m = mn[(m + n - 1) % 12 + 1];
	}
	void Date::add_year(int n)
	{
		if (m == feb && d == 29 && !leapyear(y + n))
		{
			m = mar;
			d = 1;
		}
		y += n;
	}
	bool is_date(int y, Date::Month m, int d)
	{
		if (d <= 0) return false;
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
			                    31,29,31,30,31,30,31,31,30,31,30,31 };
		if (md[leapyear(y)][m - 1] < d) return false;;
		return true;
	}
	bool leapyear(int y)
	{
		return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
	}
	bool operator==(const Date& a, const Date& b)
	{
		return (a.year() == b.year() && a.month() == b.month() && a.day() == b.day());
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a==b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
	}
	istream& operator >> (istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(ios_base::failbit);
			return is;
		}
		Chrono::Date::Month mmm[12] = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		dd = Date(y, mmm[m-1], d);
		return is;
	}
	Date::operator long()
	{
		return since;
	}
	Day day_of_week(const Date& d)
	{
		Day wd[7] = { sunday,monday,tuesday,wednesday,thursday,friday,saturday };
		const int md[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
			                    31,29,31,30,31,30,31,31,30,31,30,31 };
		int yd[2] = { 365,366 };
		if (d.year() >= 2001)
		{
			int y = d.year(), m = d.month(), dd = d.day(), i, res = 0;
			for (i = 2001; i < y; ++i) res += yd[leapyear(i)];
			for (i = 0; i < m - 1; ++i) res += md[leapyear(y)][i];
			res += dd;
			res %= 7;
			return wd[res];
		}
		else
		{
			int y = d.year(), m = d.month(), dd = d.day(), i, res = 0;
			for (i = 2000; i > y; --i)res += yd[leapyear(i)];
			for (i = 11; i > m - 1; --i) res += md[leapyear(y)][i];
			res += md[leapyear(y)][m-1] - dd;
			res = -res;
			res = ((res % 7) + 7) % 7;
			return wd[res];
		}
	}
	Date next_Sunday(const Date& d)
	{
		Date tmp = d;
		tmp.add_day(7 - day_of_week(d));
		return tmp;
	}
	Date next_weekday(const Date& d)
	{
		Date tmp = d;
		tmp.add_day(1);
		while (day_of_week(tmp) == sunday || day_of_week(tmp) == saturday) tmp.add_day(1);
		return tmp;
	}
}