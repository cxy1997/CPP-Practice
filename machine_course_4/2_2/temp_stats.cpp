#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template <class T>
void qsort(vector<T>& t, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r;
	T v = t[i];
	while (i<j)
	{
		while ((i<j) && (t[j] >= v)) --j;
		t[i] = t[j];
		while ((i<j) && (t[i] <= v)) ++i;
		t[j] = t[i];
	}
	t[i] = v;
	qsort(t, l, i - 1);
	qsort(t, i + 1, r);
}
void calculate(vector<double>& v, double& average, double& medium)
{
	qsort(v, 0, v.size() - 1);
	double sum = 0;
	for (int i = 0; i < v.size(); ++i) sum += v[i];
	if (v.size() > 0)
	{
		average = sum / v.size();
		if (v.size() % 2 == 1) medium = v[v.size() / 2];
		else medium = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;
	}
	else cout << "vector 长度为0 无法计算\n";
}
int main()
{
	ifstream fin("raw_temps.txt");
	if (fin.fail())
	{
		fin.close();
		cout << "无法打开文件！\n";
		system("pause");
		return 0;
	}
	vector<double> v;
	double t, ave, med;
	while (fin >> t) v.push_back(t);
	calculate(v, ave, med);
	fin.close();
	if (v.size() > 0)
	{
		cout << "平均数：" << ave << '\n' << "中位数：" << med << '\n';
	}
	system("pause");
}