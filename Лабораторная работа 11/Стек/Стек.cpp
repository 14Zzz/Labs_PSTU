#include<iostream>
using namespace std;

struct Node
{
    string data;
    Node* ptr_next_node = nullptr;
};

struct Stack
{
    Node* headnode = nullptr;
    Node* tailnode = nullptr;
};

void PushStack(Stack& stack, string data)
{
    Node* newnode = new Node;
    if (data == "")
    {
        data = " ";
    }
    newnode -> data = data;
    if (stack.headnode == nullptr)
    {
        stack.headnode = newnode;
        stack.tailnode = newnode;
    }
    else
    {
        newnode -> ptr_next_node = stack.headnode;
        stack.headnode = newnode;
    }
}

void PrintStack(Stack& stack, string smax)
{
    Node* currentnode = stack.headnode;
    int c, number = 1;
    while (currentnode != nullptr)
    {
        c = smax.length() - currentnode->data.length();
        cout << "Ячейка номер " << number << "-> " << "| ";
        cout << currentnode->data;
        while(c > 0)
        {
            cout << " ";
            c--;
        }
        cout << " |" << endl;
        currentnode = currentnode->ptr_next_node;
        number++;
    }
}
void pop(Stack& tmp)
{
	if (tmp.headnode != nullptr)
	{
		Node* deleted = tmp.headnode;
		tmp.headnode = tmp.headnode->ptr_next_node;
		delete deleted;
	}
}

int main()
{
    string s;
    int n, N;
    string smax;
    cout << "Введите количество элементов стека: ";
    cin >> n;
    N = n;
    Stack stack;
    Stack TMPstack;
    cin.get();
    for (int i = 1; i <= n; i++)
    {
        cout << "Введите элемент " << i << ": ";
        getline(cin, s);
        PushStack(stack, s);
        if (s.length() > smax.length())
        {
            smax = s;
        }
    }
    cout << endl << "Сформированый стек: " << endl;

    PrintStack(stack, smax);
    cout << endl << "Введите номер ячейки стека, после которого добавить элемент: ";
    cin >> n;
    
    
    Node* currentnode = stack.headnode;
    for (int i = 0; i < n; i++)
    {
        PushStack(TMPstack, currentnode->data);
        pop(stack);
        currentnode = currentnode->ptr_next_node;
    }
    
    cout << "Введите добовляемый элемент: ";
    cin.get();
    getline(cin, s);
    if (s.length() > smax.length())
    {
        smax = s;
    }
    PushStack(TMPstack, s);
    
    Node* TMPcurrentnode = TMPstack.headnode;
    for (int i = 0; i < n + 1; i++)
    {
        PushStack(stack, TMPcurrentnode->data);
        TMPcurrentnode = TMPcurrentnode->ptr_next_node;
    }
    cout << endl << "Обновлённый стек" << endl; 
    PrintStack(stack, smax);
}
