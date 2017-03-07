#include <iostream>
using namespace std;
class Divide_By_Zero{};
class Rational
{
private:
	int fz, fm;
	void simplify()
	{
		if (fm == 0) throw Divide_By_Zero();
		if (fz == 0) return;
		bool positive = (fz*fm > 0);
		if (fm < 0)
		{
			fm = -fm;
			fz = -fz;
		}
		if (!positive) fz = -fz;
		int a = (fz > fm) ? fz : fm, b = (fz > fm) ? fm : fz;
		while (a%b != 0)
		{
			a = a%b;
			if (a < b)
			{
				int tmp = a;
				a = b;
				b = tmp;
			}
		}
		fz /= b;
		fm /= b;
		if (!positive) fz = -fz;
	}
public:
	Rational(int x = 0, int y = 1) { fz = x; fm = y; (*this).simplify(); }
	Rational(const Rational& other) { fz = other.fz; fm = other.fm; }
	Rational& operator=(const Rational& other)
	{
		if (this == &other) return (*this);
		fz = other.fz; fm = other.fm; 
		return (*this);
	}
	operator double() const
	{
		if (fm == 0) throw Divide_By_Zero();
		return double(fz) / fm;
	}
	bool operator==(const Rational& other)
	{
		simplify();
		Rational tmp = other;
		tmp.simplify();
		return (fz == other.fz && fm == other.fm);
	}
	friend Rational operator+ (const Rational& a, const Rational& b);
	friend Rational operator- (const Rational& a, const Rational& b);
	friend Rational operator* (const Rational& a, const Rational& b);
	friend Rational operator/ (const Rational& a, const Rational& b);
	friend istream& operator >> (istream& in, Rational& r);
	friend ostream& operator << (ostream& out, Rational& r);
	
};
Rational operator+ (const Rational& a, const Rational& b)
{
	return Rational(a.fz*b.fm + a.fm*b.fz, a.fm*b.fm);
}
Rational operator- (const Rational& a, const Rational& b)
{
	return Rational(a.fz*b.fm - a.fm*b.fz, a.fm*b.fm);
}
Rational operator* (const Rational& a, const Rational& b)
{
	return Rational(a.fz*b.fz, a.fm*b.fm);
}
Rational operator/ (const Rational& a, const Rational& b)
{
	return Rational(a.fz*b.fm, a.fm*b.fz);
}
istream& operator >> (istream& in, Rational& r)
{
	in >> r.fz >> r.fm;
	r.simplify();
	return in;
}
ostream& operator << (ostream& out, Rational& r)
{
	out << r.fz << '/' << r.fm;
	return out;
}
int main()
{
	Rational a, b;
	cout << "�������һ��ʵ���ķ��Ӻͷ�ĸ:";
	cin >> a;
	cout << "������ڶ���ʵ���ķ��Ӻͷ�ĸ:";
	cin >> b;
	if (a == b) cout << "������ʵ�����\n"; else cout << "������ʵ�������\n";
	Rational he = a + b, cha = a - b, ji = a*b, shang = a / b;
	cout << "���ǵĺͣ�" << he << '=' << a + b << '\n';
	cout << "���ǵĲ" << cha << '=' << a - b << '\n';
	cout << "���ǵĻ���" << ji << '=' << a * b << '\n';
	cout << "���ǵ��̣�" << shang << '=' << a / b << '\n';
	system("pause");
}