#include <iostream>
using namespace std;
int main()
{
    unsigned a = 0, b = 1;
    while (1)
    {
        cout << b << '\n';
        if (b == 2971215073) break;
        b = a + b;
        a = b - a;
    }
}
