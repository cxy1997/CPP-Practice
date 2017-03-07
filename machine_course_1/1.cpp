#include <iostream>
using namespace std;
bool leapYear(int n)
{
    if ((n%400==0)||(((n&4)==0)&&(n%100!=0))) return true;else return false;
}
int main()
{
    cout<<"Please input a year: ";
    int n;
    cin>>n;
    if (n<=0) cout<<"The inputted year is not positive!\n";
    else if (leapYear(n)) cout<<"This is a leap year!\n";
    else cout<<"This is not a leap year!\n";
}
