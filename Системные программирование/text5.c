//Text5. ���� ������ S � ��������� ����. �������� ������ S � ����� �����.
#include <locale.h> 
#include <stdio.h>
#include <stdlib.h>

int main()
{
int k, g = 0;
char l = '0';
char str[k];
FILE* file;
while(l != '\n')
	{
		scanf("%c", &l);
		str[g] = l;
		g++;
	}// ��������� ��������� ��������
file = fopen("quest5.txt", "w");
for (int i = 0; i < g; i++)
	{
		fprintf(file, str[i]);
	}

file.close(); // ��������� ����
return 0;
}

