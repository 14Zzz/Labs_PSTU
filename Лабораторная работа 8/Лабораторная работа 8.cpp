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
    };

Scoolers* Skolnik = new Scoolers[6];

void PrintTXT(fstream & file)
{
    string s; 
    while(getline(file, s))
    { 
        cout << s << endl; 
    }
}

void AddTXT(fstream & file, Scoolers S)
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
    Skolnik[2] = {"Красов Александр Игоревич", "10В", "81749628381", "2, 5, 5, 5"};
    Skolnik[3] = {"Патласов Владислав Максимович", "9Г", "89468317184", "4, 4, 4, 4"};
    Skolnik[4] = {"Чащухин Максим Николаевич", "11А", "8904123456", "2, 3, 4, 4"};
    
    fstream file("file.txt", ios::trunc | ios::in | ios::out);
    
    fstream file1("file1.txt", ios::trunc | ios::in | ios::out);
    
    if (file.is_open())
    {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < 5; i++)
        {
            AddTXT(file, Skolnik[i]);
        }
        
        cout << "Содержимое файла: " << endl << endl;
        
        
        fstream file;
        file.open("file.txt");
        PrintTXT(file);
        
        
        cout << "Добавьте ученика, он станет первым в списке" << endl;
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
        cout << "Введите оценки по математике, физикe, русскому языку, литературе: ";
        getline(cin, str);
        Skolnik[5].otmetki = str;
        
        cout << endl << endl << "Новое cодержимое файла: " << endl << endl;
        
        
        file.clear();
        AddTXT(file1, Skolnik[5]);
        
        for (int i = 0; i < 5; i++)
        {
            str = Skolnik[i].otmetki;
            for (int j = 0; j <= str.length(); j++)
            {
                if (str[j] == '2')
                {
                    break;
                }
                else if (j == str.length())
                {
                    AddTXT(file1, Skolnik[i]);
                }
            }
        }
        
        remove("file.txt");
        rename("file1.txt", "file.txt");
        
        file.close();
        file.clear();
        file.open("file.txt");
        PrintTXT(file);
        
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}
