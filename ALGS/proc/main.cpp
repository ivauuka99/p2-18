//Proc1. ������� ��������� PowerA3(A, B), ����������� ������ ������� �����
//A � ������������ �� � ���������� B (A � �������, B � �������� ��������;
//��� ��������� �������� �������������). � ������� ���� ��������� ����� ������ ������� ���� ������ �����.



#include <iostream>
#include <math.h>

using namespace std;



float powerA3(float a){ //��������� ���������� ����� � 3 �������
    float answer = 0;
    answer = pow(a,3);
    return answer;
}

int main()
{

	float a[5]; // ������� ������

	for(int i = 0; i < 5; ++i){
    		cin >> a[i];
    	}

	cout << "answers: \n";

	for(int i  = 0; i < 5; ++i){ // �����
    	cout << powerA3(a[i])<< "\n";
}

return 0;
}
