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
	cout << "ת����ɣ��ѱ����� 3.out\n";
	system("pause");
}