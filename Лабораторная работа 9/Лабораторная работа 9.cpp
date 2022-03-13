#include <iostream>
#include <string>
#include<fstream>

using namespace std;

int main()
{
    int N, K;
    string s1;
    
    fstream file1("file1.txt", ios::trunc | ios::in | ios::out);
    fstream file2("file2.txt", ios::trunc | ios::in | ios::out);
    
    cout << "Введите 10 строк на русском" << endl;
    for (int i = 1; i < 11; i++)
    {
        cout << "Строка " << i << " = ";
        getline(cin, s1);
        file1 << s1 << endl;
    }
    setlocale(LC_ALL, "rus");
    cout << "Введите номер строки, с которой начать копирование: ";
    cin >> N;
    cout << "Введите номер строки, на которой закончить копирование: ";
    cin >> K;
    
    file1.clear();
    for (int i = 1; i < 11; i++)
    {
        getline(file1, s1);
        file1 << s1 << endl;
    }
    
    file1.close();
    file2.close();
}
