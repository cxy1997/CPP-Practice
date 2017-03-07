#include <iostream>
#include <vector>
using namespace std;
vector<double> input_vector(const char* s)
{
	cout << "���������� "<< s <<" �ĳ���:";
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
double exp(vector<double> price, vector<double> weight)
{
	double res = 0;
	for (int i = 0; i < weight.size(); ++i) res += price[i] * weight[i];
	return res;
}
int main()
{
	vector<double> price = input_vector("price"), weight = input_vector("weight");
	if (weight.size() > price.size())
	{
		cout << "���Ǳ��뱣֤ weight.size()<=price.size()\n";
		return 0;
	}
	cout << "�������ǣ�" << exp(price, weight) << '\n';
	system("pause");
}