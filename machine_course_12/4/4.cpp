#include <iostream>
#include <vector>
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
	return Number<T>(a.data % b.data);
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
template <class T>
T addup(const vector<T>& a, const vector<T>& b)
{
	int s = a.size();
	T res = 0;
	if (s > b.size()) s = b.size();
	for (int i = 0; i < s; ++i) res = res + a[i] * b[i];
	return res;
}
int main()
{
	vector<Number<double> > a, b;
	int c, i, d;
	cin >> c;
	for (i = 0; i < c; ++i)
	{
		cin >> d;
		a.push_back(Number<double>(d));
	}
	for (i = 0; i < c; ++i)
	{
		cin >> d;
		b.push_back(Number<double>(d));
	}
	cout << addup(a, b);
}