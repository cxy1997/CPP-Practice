#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
bool isnum(const char* s)
{
	int l = strlen(s), i, t = 0;
	for (i = 0; i < l; ++i)
	{
		if (((s[i] < '0') || (s[i] > '9')) && ((s[i] != '.') && (s[i] != '-')))
		{
			return false;
		}
		if (s[i] == '.')
		{
			if ((i == 0) || (i == l - 1))
			{
				return false;
			}
			++t;
			if (t>1)
			{
				return false;
			}
		}
		if ((s[i] == '-') && (i > 0))
		{
			return false;
		}
	}
	return true;
}
double convert(const char* s)
{
	int l = strlen(s), i, p = l, beg;
	bool neg = (s[0] == '-');
	for (i = 0; i < l; ++i)
	{
		if (s[i] == '.')
		{
			p = i;
			break;
		}
	}
	beg = (neg) ? 1 : 0;
	double k = 1, tmp = 0;
	for (i = p - 1; i >= beg; --i)
	{
		tmp += k*(s[i] - '0');
		k *= 10;
	}
	if (p<l)
	{
		k = 0.1;
		for (i = p + 1; i<l; ++i)
		{
			tmp += k*(s[i] - '0');
			k /= 10;
		}
	}
	if (neg) tmp = -tmp;
	return tmp;
}
bool input_int(int& n)
{
	char s[20];
	cin >> s;
	if (!isnum(s)) return false;
	double d = convert(s);
	n = d;
	return (n == d);
}
void qsort(vector<string>& name, vector<int>& age, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, age_t = age[i];
	string name_t = name[i];
	while (i<j)
	{
		while ((i<j) && (name[j] >= name_t)) --j;
		name[i] = name[j];
		age[i] = age[j];
		while ((i<j) && (name[i] <= name_t)) ++i;
		name[j] = name[i];
		age[j] = age[i];
	}
	name[i] = name_t;
	age[i] = age_t;
	qsort(name, age, l, i - 1);
	qsort(name, age, i + 1, r);
}
void print(vector<string>& name, vector<int>& age, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "��" << i + 1 << "���˵������ǣ�" << name[i] << "�������ǣ�" << age[i] << '\n';
	}
}
int main()
{
	cout << "����������: ";
	int n, i;
	if (!input_int(n) || n <= 0)
	{
		cout << "�ⲻ�Ǹ���������\n";
		return 0;
	}
	cin.get();
	vector<string> name;
	vector<int> age;
	char name_t[40];
	int age_t;

	for (i = 0; i < n; ++i)
	{
		cout << "������� " << i + 1 << "���˵�����: ";
		cin.getline(name_t, 40);
		name.push_back(string(name_t));
	}
	for (i = 0; i < n; ++i)
	{
		cout << "������� " << i + 1 << "���˵�����: ";
		cin >> age_t;
		age.push_back(age_t);
	}

	qsort(name, age, 0, n - 1);
	cout << "������������\n";
	print(name, age, n);
}