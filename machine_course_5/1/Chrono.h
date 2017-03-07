#ifndef CHRONO
#define CHRONO
#include <iostream>
using namespace std;
namespace Chrono
{
	class Date
	{
	public:
		enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		class Invalid{};
		Date(int y, Month m, int d);
		Date();
		Date(long s);
		int day() const{ return d; }
		Month month() const { return m; }
		int year() const{ return y; }
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		operator long();
	private:
		int y;
		Month m;
		int d;
		long since;
	};
	bool is_date(int y, Date::Month m, int d);
	bool leapyear(int y);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);	
	enum Day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };
	Day day_of_week(const Date& d);
	Date next_Sunday(const Date& d);
	Date next_weekday(const Date& d);
}
#endif
