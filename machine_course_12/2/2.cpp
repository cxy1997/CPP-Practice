#include <iostream>
using namespace std;
template <class T> class Number;
template <class T> istream& operator >> (istream& in, Number<T>& v);
template <class T> ostream& operator<< (ostream& out, const Number<T>& v);
template <class T> Number<T> operator+ (const Number<T>& v1, const Number<T>& v2);
template <class T> Number<T> operator- (const Number<T>& v1, const Number<T>& v2);
template <class T> Number<T> operator* (const Number<T>& v1, const Number<T>& v2);
template <class T> Number<T> operator/ (const Number<T>& v1, const Number<T>& v2);
template <class T> Number<T> operator% (const Number<T>& v1, const Number<T>& v2);
template <class T>
class Number
{
private:
	T data;
public:
	Number(T t = 0) :data(t) {}
	Number(const Number& other) :data(other.data) {}
	Number& operator=(const Number& other)
	{
		if (this == &other) return *this;
		data = other.data;
		return *this;
	}
	friend Number<T> operator+ <>(const Number<T>& a, const Number<T>& b);
	friend Number<T> operator- <>(const Number<T>& a, const Number<T>& b);
	friend Number<T> operator* <>(const Number<T>& a, const Number<T>& b);
	friend Number<T> operator/ <>(const Number<T>& a, const Number<T>& b);
	friend Number<T> operator% <>(const Number<T>& a, const Number<T>& b);
	friend istream& operator >> <>(istream& in, Number<T>& v);
	friend ostream& operator << <>(ostream& out, const Number<T>& v);
};
template <class T>
Number<T> operator+(const Number<T>& a, const Number<T>& b)
{
	return Number<T>(a.data + b.data);
}
template <class T>
Number<T> operator-(const Number<T>& a, const Number<T>& b)
{
	return Number<T>(a.data - b.data);
}
template <class T>
Number<T> operator*(const Number<T>& a, const Number<T>& b)
{
	return Number<T>(a.data * b.data);
}
template <class T>
Number<T> operator/(const Number<T>& a, const Number<T>& b)
{
	return Number<T>(a.data / b.data);
}
template <class T>
Number<T> operator%(const Number<T>& a, const Number<T>& b)
{
	T tmp = a.data;
	while (tmp - b.data > 0) tmp =tmp - b.data;
	return Number<T>(tmp);
}
template <class T>
istream& operator >> (istream& in, Number<T>& i)
{
	in >> i.data;
	return in;
}
template <class T>
ostream& operator << (ostream& out, const Number<T>& i)
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
	Number<int> A(a), B(b);
	cout << "A = " << A << '\n';
	cout << "B = " << B << '\n';
	cout << "A + B = " << A + B << '\n';
	cout << "A - B = " << A - B << '\n';
	cout << "A * B = " << A * B << '\n';
	cout << "A / B = " << A / B << '\n';
	cout << "A % B = " << A % B << '\n';
	double c, d;
	cout << "请输入两个小数：\nc = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	Number<double> C(c), D(d);
	cout << "C = " << C << '\n';
	cout << "D = " << D << '\n';
	cout << "C + D = " << C + D << '\n';
	cout << "C - D = " << C - D << '\n';
	cout << "C * D = " << C * D << '\n';
	cout << "C / D = " << C / D << '\n';
	cout << "C % D = " << C % D << '\n';
}