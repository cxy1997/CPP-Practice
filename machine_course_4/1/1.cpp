#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char fname[24];
	cout << "�������ļ�����";
	cin >> fname;
	ifstream fin(fname);
	if (fin.fail())
	{
		fin.close();
		cout << "�޷����ļ���\n";
		system("pause");
		return 0;
	}
	long long sum = 0, tmp;
	while (fin >> tmp) sum += tmp;
	fin.close();
	cout << "��������֮��Ϊ��" << sum << '\n';
	system("pause");
}