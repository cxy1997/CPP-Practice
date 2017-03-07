#include <iostream>
using namespace std;
int main()
{
    int i,q[17],k=2,s=0;
    char t;
    for (i=0;i<17;++i)
    {
        cin.get(t);
        q[i]=t-'0';
    }
    for (i=16;i>=0;--i)
    {
        s=(s+q[i]*(k%11))%11;
        k=(k*2)%11;
    }
    char r[12]="10X98765432";
    cout<<r[s];
}
