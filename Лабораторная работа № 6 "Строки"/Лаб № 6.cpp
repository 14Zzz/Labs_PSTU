#include <iostream>
#include <string>
using namespace std;

int main()
{
    wcin.imbue(locale(".866"));
    wcout.imbue(locale(".866"));
    wcout << L"Введите строку: ";
    wstring s, s1, s2;
    getline(wcin, s);
    for (int i = 0; i <= s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            s1 += s[i];
        }
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || (L'а' <= s[i] && s[i] <= L'я') || (L'А' <= s[i] && s[i] <= L'Я'))
        {
            s2 += s[i];
        }
    }
    s = s2 + s1;
    wcout << L"Преобразованная строка: " << s << endl;
}
