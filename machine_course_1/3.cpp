#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
bool isnum(const char* s)
{
    int l=strlen(s),i,t=0;
    for (i=0;i<l;++i)
    {
        if (((s[i]<'0')||(s[i]>'9'))&&((s[i]!='.')&&(s[i]!='-')))
        {
            return false;
        }
        if (s[i]=='.')
        {
            if ((i==0)||(i==l-1))
            {
                return false;
            }
            ++t;
            if (t>1)
            {
                return false;
            }
        }
        if ((s[i]=='-')&&(i>0))
        {
            return false;
        }
    }
    return true;
}
double convert(const char* s)
{
    int l=strlen(s),i,p=l,beg;
    bool neg=(s[0]=='-');
    for (i=0;i<l;++i)
    {
        if (s[i]=='.')
        {
            p=i;
            break;
        }
    }
    beg=(neg)?1:0;
    double k=1,tmp=0;
    for (i=p-1;i>=beg;--i)
    {
        tmp+=k*(s[i]-'0');
        k*=10;
    }
    if (p<l)
    {
        k=0.1;
        for (i=p+1;i<l;++i)
        {
            tmp+=k*(s[i]-'0');
            k/=10;
        }
    }
    if (neg) tmp=-tmp;
    return tmp;
}
int main()
{
    char s[11];
    double max;
    cout<<"Please input max (max>0): ";
    cin.getline(s,10);
    if (!isnum(s))
    {
        cout<<"This is not a number!\n";
        return 0;
    }
    else
    {
        max=convert(s);
    }
    int m=max;
    if (max<=0)
    {
        cout<<"The inputted max is not positive!\n";
    }
    else
    {
        if (max-m>0)
        {
            cout<<"Consider max as "<<m<<endl;
        }
        bool* q=new bool[m];
        int i,j;
        q[0]=false;
        for (i=1;i<max;++i)
        {
            q[i]=true;
        }
        int t=sqrt(max);
        for (i=2;i<=t;++i)
        {
            if (q[i-1])
            {
                for (j=2*i;j<=max;j+=i) q[j-1]=false;
            }
        }
        unsigned n=0;
        cout<<"The prime numbers between 1 and "<<max<<" are:\n";
        for (i=0;i<max;++i)
        {
            if (q[i])
            {
                cout<<setw(8)<<i+1;
                ++n;
                if (n%10==0) cout<<endl;
            }
        }
        if (n%10!=0) cout<<endl;
        cout<<"There are "<<n<<" prime numbers in total.\n";
    }
}
