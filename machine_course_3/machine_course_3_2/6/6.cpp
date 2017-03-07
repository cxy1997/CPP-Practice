#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> calculate(const vector<string>& v, string& longest, string& shortest, string& highest, string& lowest)
{
	int i, n = v.size();
	vector<int> res;
	if (n == 0) cout << "vector ����Ϊ0 �޷�����";
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
	cout << "�����������ĳ���:";
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
		cout << "��ĵ�һ���ַ�����" << longest << '\n';
		cout << "��̵ĵ�һ���ַ�����" << shortest << '\n';
		cout << "�ֵ����һ���ַ�����" << lowest << '\n';
		cout << "�ֵ������һ���ַ�����" << highest << '\n';
	}
	system("pause");
}
