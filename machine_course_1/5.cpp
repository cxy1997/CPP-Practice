#include <iostream>
using namespace std;
bool pal(int n)
{
    int a[4],t=0,i;
    while (n>0)
    {
        a[t]=n%10;
        ++t;
        n/=10;
    }
    for (i=0;i<t/2;++i)
    {
        if (a[i]!=a[t-i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool* q=new bool[10000];
    int i,j;
    q[0]=false;
    for (i=1;i<10000;++i)
    {
        q[i]=true;
    }
    int t=97;
    for (i=2;i<=t;++i)
    {
        if (q[i-1])
        {
            for (j=2*i;j<=10000;j+=i) q[j-1]=false;
        }
    }
    for (i=2;i<=10000;++i)
    {
        if ((q[i-1])&&(pal(i))) cout<<i<<endl;
    }

}
