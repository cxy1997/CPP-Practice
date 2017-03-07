#ifndef GET_TIME
#define GET_TIME
#include <ctime>
using namespace std;
bool prime(int n)
{
	return ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0));
}
void get_time(int& hour,int& min,int& sec)
{
	size_t T = time(NULL) + 8 * 3600;
	size_t year, month, day, tmp;
	size_t md_1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	size_t md_2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	year = 1970;
	month = 1;
	day = 1;
	hour = 0;
	min = 0;
	sec = 0;
	while (1)
	{
		if (prime(year))
			tmp = 366 * 24 * 3600;
		else tmp = 365 * 24 * 3600;
		if (T >= tmp)
		{
			T -= tmp;
			++year;
		}
		else break;
	}
	tmp = 0;
	day += T / (24 * 3600);
	T %= (24 * 3600);
	if (prime(year))
	{
		while (day > md_2[tmp])
		{
			++month;
			day -= md_2[tmp];
			++tmp;
		}
	}
	else
	{
		while (day > md_1[tmp])
		{
			++month;
			day -= md_1[tmp];
			++tmp;
		}
	}
	hour += T / 3600;
	T %= 3600;
	min += T / 60;
	T %= 60;
	sec = T;
}


#endif // !GET_TIME
