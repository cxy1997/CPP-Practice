#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	char fin_name[24], fout_name[24];
	cout << "�����������ļ�����";
	cin >> fin_name;
	ifstream fin(fin_name);
	if (fin.fail())
	{
		fin.close();
		cout << "�޷����ļ���\n";
		system("pause");
		return 0;
	}
	cout << "����������ļ�����";
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
	cout << "�ɹ���\n";
	system("pause");

}