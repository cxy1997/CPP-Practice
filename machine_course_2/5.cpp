#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "请选择功能：\n1.绝对温度转华氏温度\n2.华氏温度转绝对温度\n";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2)
    {
        cout << "输入不合法！";
        return 0;
    }
    double t;
    cin >> t;
    switch (choice)
    {
        case 1:t = (t - 273.15 - 32) / 1.8;
               break;
        case 2:t = t * 1.8 + 32 + 273.15;
    }
    if (t == floor(t)) cout << t;
        else cout << "结果非整形！";
}
