#include <iostream>
#include "Chrono.h"
using namespace std;
using namespace Chrono;
int main()
{
	Date today(1978, Chrono::Date::jun, 25), tomorrow = today;
	tomorrow.add_day(1);
	cout << today << '\n' << tomorrow<<'\n';
	cout << "请输入一个整数：";
	long s;
	cin >> s;
	Date test(s);
	cout << test << " = " << long(s);
	cout << next_weekday(test);
	system("pause");
}