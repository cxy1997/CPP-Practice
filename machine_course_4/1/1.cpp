#include <iostream>
#include <fstream>
using namespace std;
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
	long long sum = 0, tmp;
	while (fin >> tmp) sum += tmp;
	fin.close();
	cout << "所有整数之和为：" << sum << '\n';
	system("pause");
}