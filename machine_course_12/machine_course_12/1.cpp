#include <iostream>
using namespace std;
class Int
{
private:
	int data;
public:
	Int(int t=0):data(t){}
	Int(const Int& other):data(other.data){}
	Int& operator=(const Int& other)
	{
		if (this == &other) return *this;
		data = other.data;
		return *this;
	}
	friend Int operator+(const Int& a, const Int& b);
	friend Int operator-(const Int& a, const Int& b);
	friend Int operator*(const Int& a, const Int& b);
	friend Int operator/(const Int& a, const Int& b);
	friend Int operator%(const Int& a, const Int& b);
	friend istream& operator >> (istream& in, Int& i);
	friend ostream& operator << (ostream& out, const Int& i);
};
Int operator+(const Int& a, const Int& b)
{
	return Int(a.data + b.data);
}
Int operator-(const Int& a, const Int& b)
{
	return Int(a.data - b.data);
}
Int operator*(const Int& a, const Int& b)
{
	return Int(a.data * b.data);
}
Int operator/(const Int& a, const Int& b)
{
	return Int(a.data / b.data);
}
Int operator%(const Int& a, const Int& b)
{
	return Int(a.data % b.data);
}
istream& operator >> (istream& in, Int& i)
{
	in >> i.data;
	return in;
}
ostream& operator << (ostream& out, const Int& i)
{
	out << i.data;
	return out;
}
int main()
{
	int a, b;
	cout << "请输入两个整数：\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	Int A(a), B(b);
	cout << "A = " << A << '\n';
	cout << "B = " << B << '\n';
	cout << "A + B = " << A + B << '\n';
	cout << "A - B = " << A - B << '\n';
	cout << "A * B = " << A * B << '\n';
	cout << "A / B = " << A / B << '\n';
	cout << "A % B = " << A % B << '\n';

}