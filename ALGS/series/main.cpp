#include <iostream>

using namespace std;

int main()
{
//���� ������ ������������ �����. ����� �� �����.

       float a[10];// �������� ������
       for(int i = 0; i < 10; ++i){
        cin >> a[i];
       }
       float answer = 0.0; // �����
       for(int i = 0; i < 10; ++i){
           answer+= a[i];//�������� � ����������� ������
       }
       cout << "answer = " << answer;// �����
    }



