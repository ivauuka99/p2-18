// ��� ���� ����� �����. ������� ��� ����� �����, ������ �� ������� �������� ������������� ����� �� ��������� ����� (� �������� �������),
// � ������ � ������������� (����� � �������� �������).
// ���� ������������� ��� ������������� ����� � �������� ����� �����������, �� ��������������� �������������� ���� �������� ������.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// �� �������, �� �����.
int main()
{
setlocale (0,"");
    FILE *Dano, *Pol, *Otr;
     int x, prov; //a, b,
    printf("����� ������ �� ������� ���������?\n");
     printf("1 - ��.\n0 - ���.\n");
    scanf("%d", prov);
     if ( prov = 1 )
    {
        Dano = fopen("Dano.txt", "r");
        for(int i = 0; i < n; i++)
        {
            fscanf(Dano, "%d", x);

        if ( x > 0 )
        {
            Pol = fopen("Pol.txt", "w");
            fprintf(Pol, "%d", x);
        }
        else if ( x < 0)
        {
            Otr = fopen("Otr.txt", "w");
            fprintf(Pol, "%d", x);
        }
        else
        {
            printf("\n� ������� ������ ����� ���� (�����) ������ ��� ;c");
        }
        }
    }
    else
    {
        printf("\n�� ������ ������ c;\n");
        return 0;
    }

}
