#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число градусов по Фаренгейту:" << endl;
	float c;
	cin>>c;
	c = 5.0 / 9.0 * (c - 32);
	cout << "Число градусов по Цельсию = " << c << endl;
}