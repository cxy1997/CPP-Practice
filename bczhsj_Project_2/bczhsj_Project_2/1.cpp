#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <io.h>
using namespace std;
bool caps;
int choice;
template <class T>
void qsort(vector<T>& v, int l, int r)  //ģ�庯�������������͵�������������
{
	if (l >= r) return;
	T t = v[l];
	int i = l, j = r;
	while (i < j)
	{
		while (i<j && v[j]>t) --j;
		v[i] = v[j];
		while (i<j && v[i]<t) ++i;
		v[j] = v[i];
	}
	v[i] = t;
	qsort(v, l, i - 1);
	qsort(v, i + 1, r);
}
void test(const char* fname)  //���ļ�������к�����װ
{
	ifstream fin(fname);
	char foutname[32];
	strcpy_s(foutname, fname);
	int len = strlen(foutname), dot = len;
	while (foutname[dot] != '.') --dot;
	foutname[dot + 1] = 'o';
	foutname[dot + 2] = 'u';
	foutname[dot + 3] = 't';
	foutname[dot + 4] = '\0';
	ofstream fout(foutname);
	if (!fin)  //�ļ��򿪴����쳣����
	{
		cout << "�޷����ļ�: "<< fname <<"\n";
		return;
	}
	cout << "�Ѵ��ļ���" << fname << '\n';
	fout << '[' << fname << "]\n";
	char t;
	auto maxcnt = 0;  //��¼����Ƶ
	map<string, int> M;  //map�࣬�����洢���ʼ�����ִ���
	string tmp = "";  //���ڼ�¼ÿ������
	while (fin.get(t))  //ÿ�ζ���һ���ַ������ж�
	{
		if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z') || t == '_' || t == '\'' || t == '-' || t == '+')
		{
			if (caps && t >= 'A' && t <= 'Z') t = t - 'A' + 'a';
			tmp += t;
		}
		else
		{
			if (tmp == "-") tmp = "";
			if (tmp != "")  //���뵥�ʼ���Ƶ
			{
				if (tmp[0] == '\'' || tmp[0] == '\"') tmp = tmp.substr(1);
				if (tmp[tmp.size() - 1] == '\'' || tmp[tmp.size() - 1] == '\"') tmp = tmp.substr(0, tmp.size() - 1);
				if (M.count(tmp)) ++M[tmp];
				else M.insert(pair<string, int>(tmp, 1));
				if (M[tmp] > maxcnt) maxcnt = M[tmp];
			}
			tmp = "";
		}
	}
	if (tmp != "")  //���뵥�ʼ���Ƶ
	{
		if (tmp[0] == '\'' || tmp[0] == '\"' || tmp[0] == '-' || tmp[0] == '-') tmp = tmp.substr(1);
		if (tmp[tmp.size() - 1] == '\'' || tmp[tmp.size() - 1] == '\"' || tmp[tmp.size() - 1] == '-' || tmp[tmp.size() - 1] == '-') tmp = tmp.substr(0, tmp.size() - 1);
		if (M.count(tmp)) ++M[tmp];
		else M.insert(pair<string, int>(tmp, 1));
		if (M[tmp] > maxcnt) maxcnt = M[tmp];
	}
	vector<string> *v = new vector<string>[maxcnt + 1];  //vector�࣬���ڶԵ��ʰ����ִ�������
	for (auto it : M) v[it.second].push_back(it.first);
	int i, j;
	for (i = 1; i <= maxcnt; ++i) qsort(v[i], 0, v[i].size() - 1);
	/*if (choice == 2)  //�ֵ�����
	{
		for (auto it = --M.end(); it != --M.begin(); --it)
		{
			fout << it->first;
			for (auto i = it->first.size(); i < 20;++i) fout<<' ';
			fout << it->second << '\n';
		}
	}
	else if (choice == 1)  //�ֵ���˳��
	{
		for (auto it : M)
		{
			fout << it.first;
			for (auto i = it.first.size(); i < 20; ++i) fout << ' ';
			fout << it.second << '\n';
		}
	}
	else if (choice == 3)  //��Ƶ��С����
	{
		for (i = 1; i <= maxcnt; ++i) for (j = 0; j < v[i].size(); ++j)
		{
			fout << v[i][j];
			for (auto q = v[i][j].size(); i < 20; ++i) fout << ' '; 
			fout << i << '\n';
		}
	}
	else if (choice == 4)  //��Ƶ�Ӵ�С
	{
		for (i = maxcnt; i >0; --i) for (j = 0; j < v[i].size(); ++j)
		{
			fout << v[i][j];
			for (auto q = v[i][j].size(); i < 20; ++i) fout << ' ';
			fout << i << '\n';
		}
	}*/
	fout << "�ֵ���˳��\n";
	for (auto it : M)
	{
		fout << it.first;
		for (auto i = it.first.size(); i < 20; ++i) fout << ' ';
		fout << it.second << '\n';
	}
	fout << "��Ƶ����\n";
	for (i = maxcnt; i >0; --i) for (j = 0; j < v[i].size(); ++j)
	{
		fout << v[i][j];
		for (auto q = v[i][j].size(); q < 20; ++q) fout << ' ';
		fout << i << '\n';
	}
	fin.close();
	fout.close();
	cout << "��д��" << foutname << '\n';
	delete[] v;
}
int main()
{
	char dir[256], fname[256];  //�洢Ŀ¼�����ļ���
	cout << "�������ļ���·����";
	scanf("%s", dir);
	cin.get();
	int len = strlen(dir);
	if (dir[len - 1] != '\\')
	{
		dir[len] = '\\';
		dir[++len] = '\0';
	}
	strcpy(fname, dir);
	//fout << "�ļ�·����" << fname << '\n';
	dir[len] = '*';
	dir[len + 1] = '.';
	dir[len + 2] = 't';
	dir[len + 3] = 'x';
	dir[len + 4] = 't';
	dir[len + 5] = '\0';  //����txt���͵��ļ�


	_finddata_t fileDir;
	long lfDir;
	if ((lfDir = _findfirst(dir, &fileDir)) == -1l)  //�쳣�����Ҳ����ļ�
	{
		cout << "�Ҳ����ļ���\n";
		system("pause");
		return 0;
	}
	else
	{
		/*cout << "�Ƿ����ִ�Сд����Y / N�� ";
		char t;
		cin >> t;
		caps = (t == 'N' || t == 'n');  //��¼�Ƿ����ִ�Сд
		cout << "Ҫ�������ͳ�ƽ����\n1���ֵ���˳��\n2���ֵ�����\n3����Ƶ��С����\n4����Ƶ�Ӵ�С\n�������������˳�����\n";
		cin >> choice;*/
		caps = false;
		do
		{
			strcpy(fname + len, fileDir.name);  //�ļ�����·��
			test(fname);
		} while (_findnext(lfDir, &fileDir) == 0);
	}
	_findclose(lfDir);
	system("pause");
	//fout.close();
}