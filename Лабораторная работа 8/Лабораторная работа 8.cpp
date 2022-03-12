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



void AddTXT(ofstream & file, Scoolers S)
{
    file << S.FIO << endl;
    file << S.klass << endl;
    file << S.telnumber << endl;
    file << "Отметки по предметам (математика, физика, русский язык, литература): " << S.otmetki << endl;
    file << endl;
}



int main()
{
    Skolnik[0] = {"Еремеев Дмитрий Сергеевич", "9В", "86483965735", "4, 4, 2, 3"};
    Skolnik[1] = {"Полушкин Игорь Александрович", "11 А", "89765685382", "4, 4, 5, 5"};
    Skolnik[2] = {"Красов Александр Игоревич", "10 В", "81749628381", "5, 5, 5, 5"};
    Skolnik[3] = {"Патласов Владислав Максимович", "9 Г", "89468317184", "4, 4, 4, 4"};
    Skolnik[4] = {"Чащухин Максим Николаевич", "11 А", "8904123456", "2, 3, 4, 4"};
    
    ofstream file;
    file.open("file.txt");
    if (file.is_open())
    {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < 5; i++)
        {
            AddTXT(file, Skolnik[i]);
        }
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}
