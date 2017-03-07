#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> calculate(const vector<string>& v, string& longest, string& shortest, string& highest, string& lowest)
{
	int i, n = v.size();
	vector<int> res;
	if (n == 0) cout << "vector 长度为0 无法计算";
	else
	{
		longest = shortest = highest = lowest = v[0];
		for (i = 0; i < n; ++i)
		{
			res.push_back(v[i].length());
			if (v[i].length() > longest.length()) longest = v[i];
			if (v[i].length() < shortest.length()) shortest = v[i];
			if (v[i] > highest) highest = v[i];
			if (v[i] < lowest) lowest = v[i];
		}
	}
	return res;
}
vector<string> input_vector()
{
	cout << "请输入向量的长度:";
	int n, i;
	string t;
	cin >> n;
	vector<string> res;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		res.push_back(t);
	}
	return res;
}
int main()
{
	vector<string> v = input_vector();
	string longest, shortest, highest, lowest;
	calculate(v, longest, shortest, highest, lowest);
	if (v.size() > 0)
	{
		cout << "最长的第一个字符串：" << longest << '\n';
		cout << "最短的第一个字符串：" << shortest << '\n';
		cout << "字典序第一个字符串：" << lowest << '\n';
		cout << "字典序最后一个字符串：" << highest << '\n';
	}
	system("pause");
}
