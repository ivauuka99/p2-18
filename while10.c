#include <stdio.h>
int main(void)
{
   int n;
   printf("n=");

scanf ("%i", &n); //���� n

int k=0, a=3;
   while (a<n) { // ������ � �������
        a*=3;
        ++k;
   }
   printf("k= %i\n",k); // ����� k

   return 0;
}
