#include <iostream>
using namespace std;
class NegativeTemperature{};
double ctok(double c)
{
    double k = c + 273.15;
    if (k < 0) throw NegativeTemperature();
    return k;
}
int main()
{
    double c;
    cin >> c;
    try
    {
        double k = ctok(c);
        cout << k << endl;
    }
    catch (NegativeTemperature)
    {
        cout << "Illegal input!";
    }
}
