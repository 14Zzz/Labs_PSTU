#include<iostream>
using namespace std;

void ShelSort(int a[], int n)
{
    int d, j, tmp;
    d = n / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && a[j] > a[j+d])
            {
                tmp = a[j];
                a[j] = a[j + d];
                a[j + d] = tmp;
                j--;
            }
        }
        d = d / 2;
    }
}
int main()
{
        setlocale(LC_ALL, "rus");
	int n, s, z, c;
	int key, left,right,mid;
	cout << "Введите количество элементов: ";
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент номер " << i + 1 << ": ";
		cin >> s;
		a[i] = s;
	}
	cout << "Сформированный массив - ";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << a[i] << "] ";
	}
	cout << endl << "Введите элемент, который нужно заменить: ";
	cin >> z;
	cout << "Ввелите число, которое нужно поставить на место [" << z << "]: ";
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == z)
		{
			a[i] = c;
			i = n;
		}
	}
	cout << "Сформированный массив - ";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << a[i] << "] ";
	}
	// Интерполяционный 
	cout << endl << endl << "Интерполяционный поиск" << endl;
	ShelSort(a, n);
	cout << "Отсортирванный массив - ";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << a[i] << "] ";
	}
	left = 0;
	right = n - 1;
	cout << endl << "Введите элемент, ячейка правее которого будет изменена: ";
	cin >> key;
	cout << "Введите число, которое нужно поставить на ячейку правее, чем [" << key << "]: ";
	cin >> z;
	while (left <= right)
	{
		mid = left + ((key - a[left] ) * (right - left)) / (a[right] - a[left]);
		if (a[mid] < key)
		{
			right = mid + 1;
		}
		else if (a[mid] > key)
		{
			left = mid + 1;
		}
		else 
		{
			left = right + 1;
		}
	}
	if (mid + 1 > n )
	{
		cout << "Будет заменен первый элемент массива т.к. индекс найденного элемента > количества элементов массива" << endl;
		a[0] = z;
	}
	else 
	{
		a[mid + 1] = z;
	}
	cout << "Отредактированный массив - ";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << a[i] << "] ";
	}
}
