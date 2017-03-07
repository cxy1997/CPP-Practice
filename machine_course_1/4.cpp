#include <iostream>
#include <cmath>
using namespace std;
bool prime(int& n)
{
    if (n<2) return false;
    if (n<4) return true;
    if (n==4) return false;
    int qq=floor(sqrt(n)+0.5)+1;
    for (int i=2;i<qq;++i) if (n%i==0) return false;
    return true;
}
int main()
{
    cout<<"Please input n: ";
    int n,t=0,i;
    cin>>n;
    for (i=2;t<n;++i)
    {
        if (prime(i))
        {
            cout<<i<<endl;
            ++t;
        }
    }
}
