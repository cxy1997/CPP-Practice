#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <io.h>
using namespace std;
int choice;
map<string, int> Mstd;  //map�࣬������¼���ʼ���Ƶ
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
	char foutname[256];
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
		cout << "�޷����ļ�: " << fname << "\n";
		return;
	}
	cout << "�Ѵ��ļ���" << fname << '\n';
	fout << '[' << fname << "]\n";
	char t;
	auto maxcnt = 0;  //��¼����Ƶ
	map<string, int> M = Mstd;  //map�࣬�����洢���ʼ�����ִ���
	string tmp = "";  //���ڼ�¼ÿ������
	while (fin.get(t))  //ÿ�ζ���һ���ַ����д���
	{
		if (t == '/')  //ע�ʹ���
		{
			if (fin.get(t))
			{
				if (t == '/')
				{
					while (fin.get(t))
					{
						if (t == '\n') break;
					}
				}
				else if (t == '*')
				{
					char p = ' ';
					while (fin.get(t))
					{
						if (p == '*' && t == '/') break;
						else p = t;
					}
					if (p == t) t = ' ';
				}
			}
			tmp = "";
		}
		if (t == '"')
		{
			char pp = t;
			while (fin.get(t))
			{
				if (pp == '\\')
				{
					pp = ' ';
					continue;
				}
				pp = t;
				if (t == '"') break;
			}
		}
		if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z') || (t >= '0' && t <= '9') || t == '_')
		{
			tmp += t;  //�ַ�����
		}
		else
		{
			if (tmp != "" && M.find(tmp) != M.end())
			{
				++M[tmp];
				if (M[tmp] > maxcnt) maxcnt = M[tmp];
			}
			tmp = "";
		}
	}
	if (tmp != "" && M.count(tmp)) ++M[tmp];
	tmp = "";  //�����һ�����ʽ��д���
	vector<string> *v = new vector<string>[maxcnt + 1];  //vector�࣬���ڶԵ��ʰ����ִ�������
	for (auto it : M) v[it.second].push_back(it.first);
	int i, j;
	for (i = 1; i <= maxcnt; ++i) qsort(v[i], 0, v[i].size() - 1);
	/*if (choice == 2)  //�ֵ�����
	{
		for (auto it = --M.end(); it != --M.begin(); --it) if (it->second != 0)
		{
			fout << it->first;
			for (auto i = it->first.size(); i < 20; ++i) fout << ' ';
			fout << it->second << '\n';
		}
	}
	else if (choice == 1)  //�ֵ���˳��
	{
		for (auto it : M) if (it.second != 0)
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
	for (auto it : M) if (it.second != 0)
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
	ifstream sta("standard.dat");  //�洢C++�ؼ��ʵĵ����ļ���ֻ��
	string tmp;
	while (sta >> tmp) Mstd.insert(pair<string, int>(tmp, 0));
	sta.close();
	char dir[256], fname[256];  //�洢Ŀ¼�����ļ���
	cout << "�������ļ���·����";
	scanf("%s", dir);
	int len = strlen(dir);
	if (dir[len - 1] != '\\')
	{
		dir[len] = '\\';
		dir[++len] = '\0';
	}
	strcpy(fname, dir);
	dir[len] = '*';
	dir[len + 1] = '.';
	dir[len + 2] = 'c';
	dir[len + 3] = 'p';
	dir[len + 4] = 'p';
	dir[len + 5] = '\0';  //����cpp���͵��ļ�


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
		/*cout << "Ҫ�������ͳ�ƽ����\n1���ֵ���˳��\n2���ֵ�����\n3����Ƶ��С����\n4����Ƶ�Ӵ�С\n�������������˳�����\n";
		cin >> choice;*/
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