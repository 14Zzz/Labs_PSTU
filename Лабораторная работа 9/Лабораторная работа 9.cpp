#include <iostream>
#include <string>
#include<fstream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N, K, k;
    string s1;
    int counter = 0;
    string SOGL = "бвгджзйклмнпрстфхцчшщБВГДЖЗЁКЛМНПРСТФХЦЧШЩ";
    ofstream file1;
    file1.open("file1.txt");

    cout << "Введите количество строк: ";
    cin >> k;
    cout << "Введите " << k << " строк" << endl;
    getline(cin, s1);
    if (file1.is_open())
    {
        for (int i = 1; i < k + 1; i++)
        {
            cout << "Строка " << i << " = ";
            getline(cin, s1);
            file1 << s1 << endl;
        }
        cout << "Введите номер строки с которой начать копирование: ";
        cin >> N;
        cout << "Введите номер строки на которой закончить копирование: ";
        cin >> K;

        ifstream file1;
        file1.open("file1.txt");

        ofstream file2;
        file2.open("file2.txt");

        for (int i = 1; i < k + 1; i++)
        {
            if (i >= N && i <= K)
            {
                getline(file1, s1);
                file2 << s1 << endl;
                for (int m = 0; m < SOGL.length(); m++)
                {
                    for (int j = 0; j < s1.length(); j++)
                    {
                        if (s1[j] == SOGL[m])
                        {
                            counter++;
                        }
                    }
                }
            }
            else
            {
                getline(file1, s1);
            }
        }
        cout << "Количество согласных во 2-ом файле = " << counter;
        file1.close();
        file2.close();
    }
    else
    {
        cout << "Ошибка открытия файла!";
    }
}
