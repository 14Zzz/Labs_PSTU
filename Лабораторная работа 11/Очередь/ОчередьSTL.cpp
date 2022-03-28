#include <iostream>
#include <queue>  
 
using namespace std;

queue <double> q;

void Print(queue<double> qu, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << qu.front() << " ";
		qu.pop();
	}
}

void DelQ(int n)
{
    queue <double> qTMP;
    for (int i = 1; i <= n; i++)
	{
        if (i % 2 == 0)
        {
            qTMP.push(q.front());
            q.pop();
        }
        else 
        {
            q.pop();
        }
	}
	q = qTMP;
}
int main()
{
    setlocale(LC_ALL,"rus");
    
    int n, s;
    
    cout << "Введите количество элементов очереди: ";
    cin >> n;
    cout << "Введите элементs очереди: ";
    
    for (int i = 0; i < n; i++) 
    {
        cin >> s;
        q.push(s);
    }
    
    DelQ(q.size());
    cout << "Преобразованная очередь: ";
    Print(q, q.size());
}
