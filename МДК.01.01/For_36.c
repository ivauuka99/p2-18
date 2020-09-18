/*Даны целые положительные числа N и K. Найти сумму

1K + 2K + … + NK.

Чтобы избежать целочисленного переполнения, вычислять слагаемые этой суммы с помощью вещественной переменной и выводить результат как вещественное число.*/
#include <stdio.h>
#include <math.h>
int main ()
{
	int n,k,sum=0;
	printf ("Введите N и K:");
	scanf ("%d %d", &n, &k);
	for (int i = 1; i < n + 1; i++)
	{
		sum+= pow(i,k);
	}
	printf("Сумма: %d\n", sum );
}