#include <iostream>		// ���������� ���������� iostream
using namespace std;	// ���������� ������������ ���� std

int main()	// ��������� main �������
{
	setlocale(LC_ALL, "Rus");
	float a, b;	// ���������� ��� �������� �������
	cout << "������� ��� �����: ";	
	cin >> a >> b;
	cout <<"������������ �����: " << a * b;
}