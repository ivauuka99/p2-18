//Text5. ???? ?????? S ? ????????? ????. ???????? ?????? S ? ????? ?????.
#include <iostream>
#include <fstream>

int main()
{
int n, j = 0;
char l = '0';
char str[n];
FILE* file;
while(l != '\n')
	{
		scanf("%c", &l);
		str[j] = l;
		j++;
	} // ������ ������ // ��������� ��������� ��������
file = fopen("text5_ccccc.txt", "w");
for (int i = 0; i < j; i++)
	{
		fprintf(file, str[i]);
	}
 // ���������� ������ � ����
file.close(); // ��������� ����
return 0; // ���������� 0
}

