#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "��ѡ���ܣ�\n1.�����¶�ת�����¶�\n2.�����¶�ת�����¶�\n";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2)
    {
        cout << "���벻�Ϸ���";
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
        else cout << "��������Σ�";
}
