#include <iostream>
#include <cmath>
using namespace std;
void solve(double a, double b, double c, int& st, double& x1, double& x2)
{
    double f = b * b - 4 * a * c ;
    if (a == 0 && b != 0)
    {
        st = 1;
        x1 = -c / b;
        return;
    }
    if (f < 0)
    {
        st = 0;
        return;
    }
    if (f < 0.00002)
    {
        st = 1;
        x1 = x2 = -b / 2 / a;
        return;
    }
    st = 2;
    x1 = (-b + sqrt(f)) /2 /a;
    x2 = (-b - sqrt(f)) /2 /a;
}
int main()
{
    double a, b, c, x1, x2;
    int st;
    cin >> a >> b >> c;
    solve (a, b, c, st, x1, x2);
    if (st == 0) cout << "No result!\n";
        else if (st == 1) cout << "x = " << x1;
            else cout << "x1 = " << x1 <<"\nx2 = " << x2;
}
