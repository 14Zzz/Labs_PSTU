#include <iostream>		// Добавление библиотеки iostream
using namespace std;	// Объявления пространства имен std

int main()	// Обзначаем main функцию
{
	setlocale(LC_ALL, "Rus");
	float a, b;	// Переменные для значений времени
	cout << "Введите два числа: ";	
	cin >> a >> b;
	cout <<"Произведение чисел: " << a * b;
}