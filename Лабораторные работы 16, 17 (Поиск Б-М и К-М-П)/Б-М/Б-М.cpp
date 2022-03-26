#include<iostream>
#include<string>
using namespace std;

int a_max = -1;

int sdvig(char a, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == a)
        {
            return i;
        }
        else if (i == s.length() - 1)
        {
            return a_max;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    string S, s;
    int c = 1, n = 0, t;
    cout << "Введите строку: ";
    getline(cin, S);
    cout << "Введите подстроку, которую нужно удалить: ";
    getline(cin, s);
    int ptr = s.length() - 1;
    int *a = new int [s.length()];
    for (int i = s.length() - 2; i >= 0; i--)
    {
        a[i] = c;
        c += 1;
    }
    for (int i = s.length() - 2; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j] == s[i])
            {
                a[j] = a[i];
            }
        }
    }
    a[s.length() - 1] = a[0] + 1;
    for (int j = 0; j < s.length() - 2; j++)
    {
        if (s[j] == s[s.length() - 1])
        {
            a[s.length() - 1] = a[j];
        }
    }
    for (int i=0; i<s.length(); i++)
    {
        if (a[i] > a_max)
        {
            a_max = i;
        }
    }
    while (ptr < S.length())
    {
    	t = ptr;
    	for (int i = s.length() - 1; i >= 0; i--)
    	{
    		if (S[t] != s[i])
    		{
    			ptr += a[sdvig(S[t], s)];
    			if (ptr >= S.length())
    			cout << "Подстрока не найдена";
    			break;
    		}
    		if (S[t] == s[i] && i == 0)
    		{
    			S.erase(ptr - s.length() + 1, s.length());
    			cout << " Обновленная строка: " << S;
    			ptr = S.length();
    		}
    		t--;
    	}
    	c++;
    }
}
