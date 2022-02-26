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
    cout << "Отсортированный массив из " << n << " элементов = [";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << "]" << endl;
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
    ShelSort(a, n);
}
