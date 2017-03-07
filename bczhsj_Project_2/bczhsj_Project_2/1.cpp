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
void qsort(vector<T>& v, int l, int r)  //模板函数，对任意类型的向量进行排序
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
void test(const char* fname)  //对文件处理进行函数封装
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
	if (!fin)  //文件打开错误异常处理
	{
		cout << "无法打开文件: "<< fname <<"\n";
		return;
	}
	cout << "已打开文件：" << fname << '\n';
	fout << '[' << fname << "]\n";
	char t;
	auto maxcnt = 0;  //记录最大词频
	map<string, int> M;  //map类，用来存储单词及其出现次数
	string tmp = "";  //用于记录每个单词
	while (fin.get(t))  //每次读入一个字符进行判断
	{
		if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z') || t == '_' || t == '\'' || t == '-' || t == '+')
		{
			if (caps && t >= 'A' && t <= 'Z') t = t - 'A' + 'a';
			tmp += t;
		}
		else
		{
			if (tmp == "-") tmp = "";
			if (tmp != "")  //存入单词及词频
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
	if (tmp != "")  //存入单词及词频
	{
		if (tmp[0] == '\'' || tmp[0] == '\"' || tmp[0] == '-' || tmp[0] == '-') tmp = tmp.substr(1);
		if (tmp[tmp.size() - 1] == '\'' || tmp[tmp.size() - 1] == '\"' || tmp[tmp.size() - 1] == '-' || tmp[tmp.size() - 1] == '-') tmp = tmp.substr(0, tmp.size() - 1);
		if (M.count(tmp)) ++M[tmp];
		else M.insert(pair<string, int>(tmp, 1));
		if (M[tmp] > maxcnt) maxcnt = M[tmp];
	}
	vector<string> *v = new vector<string>[maxcnt + 1];  //vector类，用于对单词按出现次数排序
	for (auto it : M) v[it.second].push_back(it.first);
	int i, j;
	for (i = 1; i <= maxcnt; ++i) qsort(v[i], 0, v[i].size() - 1);
	/*if (choice == 2)  //字典序倒序
	{
		for (auto it = --M.end(); it != --M.begin(); --it)
		{
			fout << it->first;
			for (auto i = it->first.size(); i < 20;++i) fout<<' ';
			fout << it->second << '\n';
		}
	}
	else if (choice == 1)  //字典序顺序
	{
		for (auto it : M)
		{
			fout << it.first;
			for (auto i = it.first.size(); i < 20; ++i) fout << ' ';
			fout << it.second << '\n';
		}
	}
	else if (choice == 3)  //词频从小到大
	{
		for (i = 1; i <= maxcnt; ++i) for (j = 0; j < v[i].size(); ++j)
		{
			fout << v[i][j];
			for (auto q = v[i][j].size(); i < 20; ++i) fout << ' '; 
			fout << i << '\n';
		}
	}
	else if (choice == 4)  //词频从大到小
	{
		for (i = maxcnt; i >0; --i) for (j = 0; j < v[i].size(); ++j)
		{
			fout << v[i][j];
			for (auto q = v[i][j].size(); i < 20; ++i) fout << ' ';
			fout << i << '\n';
		}
	}*/
	fout << "字典序顺序：\n";
	for (auto it : M)
	{
		fout << it.first;
		for (auto i = it.first.size(); i < 20; ++i) fout << ' ';
		fout << it.second << '\n';
	}
	fout << "词频降序：\n";
	for (i = maxcnt; i >0; --i) for (j = 0; j < v[i].size(); ++j)
	{
		fout << v[i][j];
		for (auto q = v[i][j].size(); q < 20; ++q) fout << ' ';
		fout << i << '\n';
	}
	fin.close();
	fout.close();
	cout << "已写入" << foutname << '\n';
	delete[] v;
}
int main()
{
	char dir[256], fname[256];  //存储目录名与文件名
	cout << "请输入文件夹路径：";
	scanf("%s", dir);
	cin.get();
	int len = strlen(dir);
	if (dir[len - 1] != '\\')
	{
		dir[len] = '\\';
		dir[++len] = '\0';
	}
	strcpy(fname, dir);
	//fout << "文件路径：" << fname << '\n';
	dir[len] = '*';
	dir[len + 1] = '.';
	dir[len + 2] = 't';
	dir[len + 3] = 'x';
	dir[len + 4] = 't';
	dir[len + 5] = '\0';  //查找txt类型的文件


	_finddata_t fileDir;
	long lfDir;
	if ((lfDir = _findfirst(dir, &fileDir)) == -1l)  //异常处理：找不到文件
	{
		cout << "找不到文件！\n";
		system("pause");
		return 0;
	}
	else
	{
		/*cout << "是否区分大小写？（Y / N） ";
		char t;
		cin >> t;
		caps = (t == 'N' || t == 'n');  //记录是否区分大小写
		cout << "要怎样输出统计结果？\n1、字典序顺序\n2、字典序倒序\n3、词频从小到大\n4、词频从大到小\n输入其他数字退出程序\n";
		cin >> choice;*/
		caps = false;
		do
		{
			strcpy(fname + len, fileDir.name);  //文件绝对路径
			test(fname);
		} while (_findnext(lfDir, &fileDir) == 0);
	}
	_findclose(lfDir);
	system("pause");
	//fout.close();
}