//���� ��� ����� � ����� ������������� ����� N � K. ������� ��������� ����
// � ��������� ������ � �������� � ���� N �����, ������ �� ������� ������� �� K �������� �*� (���������).


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    int n, k; // n ���-�� �����, k ��� �� ����� � ������

    //���� ������
    cout << "enter numbers of strings\n";
    cin >> n;
    cout << "enter number of symbols \" * \" \n";
    cin >> k;

    //���������� ��� ����� �����
    string filename;
    //���� ����� �����
    cout << "enter file name ";
    cin >> filename;
    //�������� ������� �� ���������� fstream ��� ������ � �������
    ofstream fileOBJ;
    fileOBJ.open(filename + ".txt"); //�������� ����� � �������� ��������� + ����������� ����� txt
    //��������� ���� ��� ���������� ����� ��������
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            fileOBJ << '*';
        }
        fileOBJ << "\n";
    }

    //�������� ����� ��� ������������ ������
    fileOBJ.close();
return 0;
}
