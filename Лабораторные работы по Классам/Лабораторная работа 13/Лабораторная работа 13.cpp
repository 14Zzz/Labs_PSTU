#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int set;
float num = 0.0;

class equals
{
public:
	bool operator() (int tmp)
	{
		return tmp == set;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	list<float> Spisok;
	list <float>::iterator Spisok_Iter;

	int tmp;

	int s;


	cout << "Введите размер списка: ";
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		cout << "Введите элемент " << i + 1 << ": ";
		cin >> tmp;
		Spisok.push_back(tmp);
	}


	cout << "\nИзначальный список: ";
	for (Spisok_Iter = Spisok.begin(); Spisok_Iter != Spisok.end(); Spisok_Iter++)
		cout << " " << *Spisok_Iter;
	cout << endl;
	auto max = max_element(Spisok.begin(), Spisok.end());
	set = *max;


	Spisok.remove_if(equals());
	Spisok.push_front(set);
	cout << "\nМаксимальный элемент в начале списка: ";
	for (Spisok_Iter = Spisok.begin(); Spisok_Iter != Spisok.end(); Spisok_Iter++)
		cout << " " << *Spisok_Iter;
	cout << endl;


	auto min = min_element(Spisok.begin(), Spisok.end());
	set = *min;
	Spisok.remove(set);
	cout << "После удаления минимального элемента списка: ";
	for (Spisok_Iter = Spisok.begin(); Spisok_Iter != Spisok.end(); Spisok_Iter++)
	{
		cout << " " << *Spisok_Iter;
		num += *Spisok_Iter;
	}
	cout << endl;


	num = num / (s - 1);
	for (Spisok_Iter = Spisok.begin(); Spisok_Iter != Spisok.end(); Spisok_Iter++)
	{
		*Spisok_Iter += num;
	}
	cout << "\nСписок после добавления среднего арефметического: ";
	for (Spisok_Iter = Spisok.begin(); Spisok_Iter != Spisok.end(); Spisok_Iter++)
		cout << " " << *Spisok_Iter;
	cout << endl;

	return 0;
}
