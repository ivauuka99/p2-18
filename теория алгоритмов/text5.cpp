// ���� ������ S � ��������� ����. �������� ������ S � ����� �����
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
string S = "string"; // ������ ������ S
ofstream file("werty.txt"); // ��������� ��������� ��������
file << S; // ���������� ������ � ����
file.close(); // ��������� ����
return 0; // ���������� 0
}
