#include <iostream>
using namespace std;
double ctok(double c)
{
    double k = c + 273.15;
    return k;
}
int main()
{
    double c;
    cin >> c;
    double k = ctok( c );
    if (k < 0) cout << "Illegal input!";
        else cout << k << endl;
}
