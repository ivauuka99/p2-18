// ���� ����� ����� N � ����� �� N ����� �����.
 //������� � ��� �� ������� ��� ������ ����� �� ������� ������ � ���������� K ����� �����.
#include <stdio.h>

int main(void)
{
    int i,n,k,num=0;
    printf("N:");
    scanf("%i", &n);
    for (i=1; i<=n; ++i){
        printf("%i:",i);
        scanf("%i", &k);
        if (k%2==0){
                printf("%i\n",k);
                ++num;
        }
    }
    printf("%i\n",num);
    return 0;
}
