/*Case2�. ���� ����� ����� K. ������� ������-�������� ������, ��������������� ����� K (1 � ������, 2 � ��������������������, 3 � ������������������, 4 � �������, 5 � ��������).
 ���� K �� ����� � ��������� 1�5, �� ������� ������ �������.
 ������� ���������: ������� � ������*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "");
    int k;
    cout << "k = ";
    cin >> k;
    switch (k)
    {
        case 1:cout<<"�����";
        break;
        case 2:cout<<"�������������������";
        break;
        case 3:cout<<"�����������������";
        break;
        case 4:cout<<"������";
        break;
        case 5:cout<<"�������";
        break;
        default:cout<<"������";
    }
    cout << endl;
}
