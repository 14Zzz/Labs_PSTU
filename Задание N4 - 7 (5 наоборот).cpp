#include <iostream>		// Добавление библиотеки iostream
using namespace std;	// Объявления пространства имен std

int main()	// Обзначаем main функцию
{
	setlocale(LC_ALL, "Rus");
	char a, b, c, d, e;	// Переменные для значений времени
	cout << "Введите 5 символов: ";
	cin >> a >> b >> c >> d >> e;
	cout << e << d << c << b << a;
}
