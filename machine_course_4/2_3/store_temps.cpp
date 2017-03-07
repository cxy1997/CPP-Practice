#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Reading
{
	int hour;
	double temperature;
	Reading(int h, double t) :hour(h), temperature(t) {}
};
char randmark()
{
	return (rand() % 2) ? 'c' : 'f';
}
int main()
{
	srand(time(NULL));
	int n, i;
	ofstream fout("raw_temps.txt");
	cout << "请输入温度个数：";
	cin >> n;
	for (i = 0; i < n; ++i) fout << rand() / double(RAND_MAX) * 100 - 50 << ' ' << randmark() << '\n';
	fout.close();
	cout << "完成！";
	system("pause");
}