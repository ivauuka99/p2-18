// ���� ������������ ����� A � ����� ����� N (> 0).
//��������� ���� ����, ������� ��� ����� ������� ����� A �� 1 �� N.
#include <iostream>
using namespace std;

int main()
{
    float a;
    cout << "A:";
    cin >> a;

   int b;
   cout << "b:";
   cin >> b;

   float c=1;
   int i;
   for  (i =1; i<=b; ++i){
      c *= a;
     cout << c << endl;
   }
   return 0;
}
