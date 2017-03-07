#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void lower(char* s)
{
    int l = strlen(s), i;
    for (i = 0; i < l; ++i)
        if ( 'A' <= s[i] && s[i] <= 'Z' )
            s[i] = s[i] - 'A' + 'a';
}
void print( vector<int> v )
{
    int s = v.size(), i, m = 0;
    for (i = 0; i < s; ++i)
    {
        cout << v[i] << ", ";
        m += v[i];
    }
    cout <<"\n总和: " << m << '\n';
}
int main()
{
    char* days[21] = {"mon", "monday", "星期一",
                      "tue", "tuesday", "星期二",
                      "wed", "wednesday", "星期三",
                      "thu", "thusday", "星期四",
                      "fri", "friday", "星期五",
                      "sat", "saturday", "星期六",
                      "sun", "sunday", "星期日" };
    char s[10];
    int p, i, c = 0;
    vector <int> v[7];
    cout << "请输入星期几 数字(用空格分隔):\n";
    while (cin >> s >> p)
    {
        lower(s);
        for (i = 0; i < 21; ++i)
            if ( strcmp( days[i], s ) == 0 ) break;
        if ( i < 21 ) v[ i/3 ].push_back(p);
            else ++c;
        cout << "请输入星期几 数字(用空格分隔): (输入Ctrl+Z结束)\n";
    }
    for (i = 0; i < 7; ++i)
    {
        cout << days[3*i+2] << ": ";
        print( v[i] );
    }
    cout << "被拒绝数值: " << c;
}
