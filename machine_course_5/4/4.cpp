#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class record
{
public:
	int data, times;
	record(int d=0):data(d),times(1){}
	friend class stat;
	friend ostream& operator << (ostream& out, const record& r);
	friend bool operator > (const record& a, const record& b);
	friend bool operator >= (const record& a, const record& b);
	friend bool operator < (const record& a, const record& b);
	friend bool operator <= (const record& a, const record& b);
};
bool operator > (const record& a, const record& b)
{
	return (a.data > b.data);
}
bool operator >= (const record& a, const record& b)
{
	return (a.data >= b.data);
}
bool operator < (const record& a, const record& b)
{
	return (a.data < b.data);
}
bool operator <= (const record& a, const record& b)
{
	return (a.data <= b.data);
}
class stats
{
private:
	vector<record> v;
public:
	void add(int n)
	{
		int i;
		for (i = 0; i < v.size(); ++i) if (n == v[i].data) break;
		if (i != v.size()) ++v[i].times; else v.push_back(record(n));
	}
	friend ostream& operator << (ostream& out, const stats& s);
	void qsort()
	{
		qsort(0, v.size() - 1);
	}
	void qsort(int l, int r)
	{
		if (l >= r) return;
		int i = l, j = r;
		record t = v[i];
		while (i<j)
		{
			while ((i<j) && (v[j] >= t)) --j;
			v[i] = v[j];
			while ((i<j) && (v[i] <= t)) ++i;
			v[j] = v[i];
		}
		v[i] = t;
		qsort(l, i - 1);
		qsort(i + 1, r);
	}
};
ostream& operator << (ostream& out, const record& r)
{
	out << r.data;
	if (r.times > 1) out << ' ' << r.times;
	cout << '\n';
	return out;
}
ostream& operator << (ostream& out, const stats& s)
{
	for (int i = 0; i < s.v.size(); ++i) out << s.v[i];
	return out;
}
int main()
{
	char fname[24];
	cout << "请输入文件名：";
	cin >> fname;
	ifstream fin(fname);
	if (fin.fail())
	{
		fin.close();
		cout << "无法打开文件！\n";
		system("pause");
		return 0;
	}
	int t;
	stats ss;
	while (!fin.eof())
	{
		fin >> t;
		ss.add(t);
	}
	ss.qsort();
	fin.close();
	cout << ss;
	system("pause");
}