#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	char fin_name[24], fout_name[24];
	cout << "请输入输入文件名：";
	cin >> fin_name;
	ifstream fin(fin_name);
	if (fin.fail())
	{
		fin.close();
		cout << "无法打开文件！\n";
		system("pause");
		return 0;
	}
	cout << "请输入输出文件名：";
	cin >> fout_name;
	ofstream fout(fout_name);
	int ac = 0;
	double d;
	while (fin >> d)
	{
		fout << setw(20) << setprecision(8) << scientific << d;
		ac = (ac + 1) % 4;
		if (!ac) fout << '\n';
	}
	fin.close();
	fout.close();
	cout << "成功！\n";
	system("pause");

}