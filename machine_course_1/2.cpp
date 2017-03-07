#include <iostream>
using namespace std;
bool pass(int* q)
{
    if (((q[0]*10+q[1])/q[2])!=(q[3]*q[4]-q[5])) return false;
    if ((q[6]-q[7]*q[8])!=(q[3]*q[4]-q[5])) return false;
    return true;
}
void search(int t,bool* p,int* rec)
{
    if (t==9)
    {
        rec[8]=45;
        for (int i=0;i<8;++i) rec[8]-=rec[i];
        if (pass(rec))
        {
            for (int i=0;i<9;++i) cout<<rec[i]<<' ';
            cout<<endl;
        }
        return;
    }
    if (t==3)
    {
        int i;
        for (i=1;i<=9;++i) if (((rec[0]*10+rec[1])%i==0)&&(p[i-1]))
        {
            rec[2]=i;
            p[i-1]=false;
            search(4,p,rec);
            p[i-1]=true;
        }
        return;
    }
    int i;
    for (i=1;i<=9;++i) if (p[i-1])
    {
        rec[t-1]=i;
        p[i-1]=false;
        search(t+1,p,rec);
        p[i-1]=true;
    }
}
int main()
{
    bool p[9]={true,true,true,true,true,true,true,true,true};
    int rec[9];
    search(1,p,rec);
}
