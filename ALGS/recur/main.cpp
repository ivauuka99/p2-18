//������� ����������� ������� Fact(N) ������������� ����, ����������� �������� ����������

#include <iostream>


using namespace std;

float Fact(float n){
if(n == 1 || n == 0){ // 1! = 1,  0! = 1//� ����� ��� ������ �� ����������� �������;
    return 1;
}
float answer; //���������� � �������
answer = n * Fact(n - 1); // ��������, ������� ����� ���������� �� ��������� ���������� ���� ���� �� ����� 1;
return answer;//���������� �����
}

int main()
{
    int a;//���� �����
    cout << "enter n! ";
    cin >> a;
    //����� �������
    cout << "asnwer = " << Fact(a);
return 0;
}
