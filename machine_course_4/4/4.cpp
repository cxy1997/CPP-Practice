#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(const string& s)
{
	vector<string> res;
	int i = 0, l = s.length();
	vector<int> cut;
	cut.push_back(-1);
	for (i = 0; i < l; ++i) if (s[i] == ' ') cut.push_back(i);
	cut.push_back(l);
	l = cut.size() - 1;
	for (i = 0; i < l; ++i) if (cut[i + 1] - cut[i] > 1) res.push_back(s.substr(cut[i] + 1, cut[i + 1] - cut[i] - 1));
	return res;
}
vector<string> split(const string& s, const string& w)
{
	vector<string> res;
	int i = 0, l = s.length(), wl = w.length();
	vector<int> cut;
	cut.push_back(-1);
	for (i = 0; i < l; ++i) if (s[i] == ' ' || (w.find(s[i])>=0 && w.find(s[i])<wl)) cut.push_back(i);
	cut.push_back(l);
	l = cut.size() - 1;
	for (i = 0; i < l; ++i) if (cut[i + 1] - cut[i] > 1) res.push_back(s.substr(cut[i] + 1, cut[i + 1] - cut[i] - 1));
	return res;
}
void print(vector<string> v)
{
	for (int i = 0; i < v.size(); ++i) cout << v[i] << '\n';
}
int main()
{
	vector<string> res;
	char ss[1000], ww[1000];
	cin.getline(ss, 1000);
	cin.getline(ww, 1000);
	res = split(ss, ww);
	print(res);
	system("pause");
}