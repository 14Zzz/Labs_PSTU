#include<iostream>

using namespace std;

void quick(int a[], int left, int right)
{
    int L = left, R = right, tmp, b = a[(L + R) / 2];
    while (L < R)
    {
        while(a[L] < b)
        {
            L++;
        }
        while(a[R] > b)
        {
            R--;
        }
        if (L <= R)
        {
            tmp = a[L];
            a[L] = a[R];
            a[R] = tmp;
            L++;
            R--;
        }
    }
    if (left < R)
	{
		quick(a, left, R);
	}
	if (L < right)
	{
		quick(a, L, right);
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    
    cout << "Сформированный массив из " << n << " элементов = [";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << "]" << endl;
    quick(a, 0, n - 1);
    cout << "Отсортированный массив из " << n << " элементов = [";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << "]" << endl;
}
