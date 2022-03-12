#include<iostream>
#include<string>
#include<fstream>

using namespace std;


struct Scoolers
    {
        string FIO;
        string klass;
        string telnumber;
        string otmetki;
        void Print() {cout << FIO << klass << telnumber << otmetki << endl;}
    };

Scoolers* Skolnik = new Scoolers[6];

void PrintTXT(ifstream & file)
{
    string s; 
    while(getline(file, s))
    { 
        cout << s << endl; 
    }
}

void AddTXT(ofstream & file, Scoolers S)
{
    file << "ФИО: " << S.FIO << endl;
    file << "Класс: " << S.klass << endl;
    file << "Телефон: " << S.telnumber << endl;
    file << "Отметки по предметам (математика, физика, русский язык, литература): " << S.otmetki << endl;
    file << endl;
}



int main()
{
    Skolnik[0] = {"Еремеев Дмитрий Сергеевич", "9В", "86483965735", "4, 4, 2, 3"};
    Skolnik[1] = {"Полушкин Игорь Александрович", "11А", "89765685382", "4, 4, 5, 5"};
    Skolnik[2] = {"Красов Александр Игоревич", "10В", "81749628381", "5, 5, 5, 5"};
    Skolnik[3] = {"Патласов Владислав Максимович", "9Г", "89468317184", "4, 4, 4, 4"};
    Skolnik[4] = {"Чащухин Максим Николаевич", "11А", "8904123456", "2, 3, 4, 4"};
    
    ofstream file;
    file.open("file.txt");
    if (file.is_open())
    {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < 5; i++)
        {
            AddTXT(file, Skolnik[i]);
        }
        
        cout << "Содержимое файла: " << endl << endl;
        
        ifstream file;
        file.open("file.txt");
        PrintTXT(file);
        
        fstream clear_file("test.txt", ios::out);
        
        cout << "Добавьте ученика" << endl;
        string str;
        cout << "Введите ФИО: ";
        getline(cin, str);
        Skolnik[5].FIO = str;
        cout << "Введите Класс: ";
        getline(cin, str);
        Skolnik[5].klass = str;
        cout << "Введите телефон: ";
        getline(cin, str);
        Skolnik[5].telnumber = str;
        cout << "Введите оценки по математике, физикe, русскому языку, литературе (цифры через пробел): ";
        getline(cin, str);
        Skolnik[5].otmetki = str;

    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}
