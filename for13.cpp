//Дано целое число N (>0).
//Найти значение выражения 1.1-1.2+1.3-... (N слагаемых,
//знаки чередуются). Условный оператор не использовать.
#include <iostream>

using namespace std;

int main()
{
    int N, a = 1;
    float sum = 0,  x = 1;
    cout << "Vvedite N: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        x += 0.1;
        sum += a * x;
        a = -a;
    }
    cout << sum;
}
