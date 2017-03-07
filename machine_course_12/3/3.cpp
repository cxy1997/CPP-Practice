#include <iostream>
#include <vector>
using namespace std;
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
	vector<double> a, b;
	int c, i, d;
	cin >> c;
	for (i = 0; i < c; ++i)
	{
		cin >> d;
		a.push_back(d);
	}
	for (i = 0; i < c; ++i)
	{
		cin >> d;
		b.push_back(d);
	}
	cout << addup(a, b);
}