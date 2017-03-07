#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <class T>
void qsort(vector<T>& v, int l, int r)
{
	if (l >= r) return;
	T t = v[l];
	int i = l, j = r;
	while (i < j)
	{
		while (i<j && v[j]>t) --j;
		v[i] = v[j];
		while (i<j && v[i]<t) ++i;
		v[j] = v[i];
	}
	v[i] = t;
	qsort(v, l, i - 1);
	qsort(v, i + 1, r);
}
void convert(list<int>& a,vector<double>& b)
{
	for (list<int>::iterator it = a.begin(); it != a.end(); ++it) b.push_back(*it);
}
int main()
{
	list<int> a;
	a.push_back(1);
	a.push_back(0);
	a.push_back(2);
	a.push_back(3);
	a.push_back(7);
	a.push_back(6);
	a.push_back(4);
	a.push_back(8);
	a.push_back(5);
	a.push_back(9);
	vector<double> b;
	convert(a, b);
	cout << b.size() << ": ";
	for (int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
	qsort(b,0,b.size()-1);
	cout << '\n'<< b.size() << ": ";
	for (int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
}