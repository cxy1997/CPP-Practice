#include <iostream>
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
template <class T>
void calculate(vector<T> v, T& min, T& max, double& average, double& medium)
{
	qsort(v, 0, v.size() - 1);
	double sum = 0;
	for (int i = 0; i < v.size(); ++i) sum += v[i];
	if (v.size() > 0)
	{
		min = v[0];
		max = v[v.size() - 1];
		average = sum / v.size();
		if (v.size() % 2 == 1) medium = v[v.size() / 2];
		else medium = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;
	}
	else cout << "vector 长度为0 无法计算\n";
}
vector<double> input_vector()
{
	cout << "请输入向量的长度:";
	int n, i;
	double t;
	cin >> n;
	vector<double> res;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		res.push_back(t);
	}
	return res;
}
void print(vector<double> v)
{
	for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
	cout << '\n';
}
int main()
{
	vector<double> v = input_vector();
	double min, max, average, medium;
	calculate(v, min, max, average, medium);
	if (v.size()>0)
	{
		cout << "最小元素：" << min << '\n';
		cout << "最大元素：" << max << '\n';
		cout << "均值：" << average << '\n';
		cout << "中位值：" << medium << '\n';
	}
	system("pause");
}