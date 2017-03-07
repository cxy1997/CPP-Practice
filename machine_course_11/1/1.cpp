#include <iostream>
using namespace std;
void to_lower(char* s)
{
	char *t = s;
	while (*t != '\0')
	{
		if (*t >= 'A' && *t <= 'Z') *t = *t - 'A' + 'a';
		++t;
	}
}
char* Strdup(const char* s)
{
	int len = 0;
	const char *t = s;
	while (*t != '\0')
	{
		++len;
		++t;
	}
	char *tmp = new char[len + 1];
	for (int i = 0; i < len; ++i) tmp[i] = s[i];
	tmp[len] = '\0';
	return tmp;
}
const char* findx(const char* s, const char* x)
{
	int ls = 0, lx = 0, i, j;
	const char *t = s;
	while (*t != '\0')
	{
		++ls;
		++t;
	}
	t = x;
	while (*t != '\0')
	{
		++lx;
		++t;
	}
	for (i = 0; i <= ls - lx; ++i) if (s[i] == x[0])
	{
		bool flag = true;
		for (j = 0; j < lx; ++j) if (s[i + j] != x[j])
		{
			flag = false;
			break;
		}
		if (flag) return &s[i];
	}
	return NULL;
}
int main()
{
	cout << "ÇëÊäÈë×Ö·û´®s£º";
	char s[256];
	cin >> s;
	to_lower(s);
	cout << "to_lower(s):\n" << s << '\n';
	char *t = Strdup(s);
	cout << "strdup(s):\n" << t << '\n';
	delete[] t;
	cout << "ÇëÊäÈë×Ö·û´®x£º";
	char x[100];
	cin >> x;
	if (findx(s, x) != NULL) cout << "findx(s,x):\n" << findx(s, x) << '\n'; else cout << "Not find.\n";
}