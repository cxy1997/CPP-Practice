#include <iostream>
#include <vector>
using namespace std;
vector<int> reverse_1(vector<int>& ori)
{
	vector<int> res;
	for (int i = ori.size() - 1; i >= 0; --i) res.push_back(ori[i]);
	return res;
}
void reverse_2(vector<int>& v)
{
	int tmp, l = v.size();
	for (int i = 0; i < l / 2; ++i)
	{
		tmp = v[i];
		v[i] = v[l - i - 1];
		v[l - i - 1] = tmp;
	}
}
vector<int> input_vector()
{
	cout << "请输入向量的长度:";
	int n, i, t;
	cin >> n;
	vector<int> res;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		res.push_back(t);
	}
	return res;
}
void print(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
	cout << '\n';
}
int main()
{
	vector<int> v1 = input_vector(), v2 = reverse_1(v1);
	reverse_2(v1);
	cout << "reverse_1:\n";
	print(v1);
	cout << "reverse_2:\n";
	print(v2);
	system("pause");
}