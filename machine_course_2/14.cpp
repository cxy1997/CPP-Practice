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
    cout <<"\n�ܺ�: " << m << '\n';
}
int main()
{
    char* days[21] = {"mon", "monday", "����һ",
                      "tue", "tuesday", "���ڶ�",
                      "wed", "wednesday", "������",
                      "thu", "thusday", "������",
                      "fri", "friday", "������",
                      "sat", "saturday", "������",
                      "sun", "sunday", "������" };
    char s[10];
    int p, i, c = 0;
    vector <int> v[7];
    cout << "���������ڼ� ����(�ÿո�ָ�):\n";
    while (cin >> s >> p)
    {
        lower(s);
        for (i = 0; i < 21; ++i)
            if ( strcmp( days[i], s ) == 0 ) break;
        if ( i < 21 ) v[ i/3 ].push_back(p);
            else ++c;
        cout << "���������ڼ� ����(�ÿո�ָ�): (����Ctrl+Z����)\n";
    }
    for (i = 0; i < 7; ++i)
    {
        cout << days[3*i+2] << ": ";
        print( v[i] );
    }
    cout << "���ܾ���ֵ: " << c;
}
