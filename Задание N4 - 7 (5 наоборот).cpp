#include <iostream>		// ���������� ���������� iostream
using namespace std;	// ���������� ������������ ���� std

int main()	// ��������� main �������
{
	setlocale(LC_ALL, "Rus");
	char a, b, c, d, e;	// ���������� ��� �������� �������
	cout << "������� 5 ��������: ";
	cin >> a >> b >> c >> d >> e;
	cout << e << d << c << b << a;
}