#include<iostream>

using namespace std;

// Функция
int sedlovie (int strok, int stolbcov, int a[6][7])
{
    for (int j = 0; j < strok; j++)
    {
        for (int i = 0; i < stolbcov; i++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод числа элементов
    int strok = 6, stolbcov = 7;
    
    // Создание массива

    int a[strok][stolbcov];
    for (int j = 0; j < strok; j++)
    {
        for (int i = 0; i < stolbcov; i++)
        {
            a[j][i]= rand() % 100;
        }
    }

    // Вывод массива
    cout << "Сформированная матрица" << endl;

    for (int j = 0; j < strok; j++)
    {
        for (int i = 0; i < stolbcov; i++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    sedlovie(strok, stolbcov, a);
}
