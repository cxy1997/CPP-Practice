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
	ofstream fout("3.out");
	char t;
	while (!fin.eof())
	{
		fin.get(t);
		if (t >= 'A' && t <= 'Z') t = t - 'A' + 'a';
		fout.put(t);
	}
	fin.close();
	fout.close();
	cout << "转换完成，已保存至 3.out\n";
	system("pause");
}