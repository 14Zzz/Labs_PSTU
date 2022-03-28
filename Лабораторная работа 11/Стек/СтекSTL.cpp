#include <iostream>
#include <stack>  
 
using namespace std;

stack <string> st;

void Print(stack<string> st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "| " << st.top() << " |" << endl;
		st.pop();
	}
}

void ADD(int ptr, string add)
{
    stack <string> stTMP;
	for (int i = 0; i < ptr - 1; i++)
	{
		stTMP.push(st.top());
		st.pop();
	}
	st.push(add);
	for (int i = 0; i < ptr - 1; i++)
	{
		st.push(stTMP.top());
		stTMP.pop();
	}
}

int main()
{
    setlocale(LC_ALL,"rus");
    
    int n, ptr;
    string s, add;
    
    cout << "Введите количество элементов стека: ";
    cin >> n;
    cout << "Введите элементы стека: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> s;
        st.push(s);
    }
    cout << "Сформированный стек: " << endl;
    Print(st, st.size());
    
    cout << "Введите на какой номер добавить элемент: ";
    cin >> ptr;
    cout << "Введите добавляемый элемент: ";
    cin >> add;
    
    cout << "Преобразованный стек: " << endl;
    ADD(ptr, add);
    Print(st, st.size());
}
