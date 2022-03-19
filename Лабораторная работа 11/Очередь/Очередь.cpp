#include<iostream>
using namespace std;

struct Node
{
    double data;
    Node* ptr_next_node = nullptr;
};

struct Queue
{
    Node* headnode = nullptr;
    Node* tailnode = nullptr;
};

void PushQueue(Queue& queue, double data)
{
    Node* newnode = new Node;
    newnode -> data = data;
    if (queue.headnode == nullptr)
    {
        queue.headnode = newnode;
        queue.tailnode = newnode;
    }
    else
    {
        newnode -> ptr_next_node = nullptr;
        queue.tailnode -> ptr_next_node = newnode;
        queue.tailnode = newnode;
    }
}

void PrintQueue(Queue& queue)
{
    Node* currentnode = queue.headnode;
    while (currentnode != nullptr)
    {
        cout << "|" << currentnode->data << "| ";
        currentnode = currentnode->ptr_next_node;
    }
}
void changeQueue(Queue& queue)
{
	Node* currentnode = queue.headnode;
	Node* prednode = queue.headnode;
	int count = 1;
	while (currentnode != nullptr)
	{
		if (count % 2 == 0)
		{
			prednode->ptr_next_node = currentnode->ptr_next_node;
			prednode = currentnode->ptr_next_node;
		}
		currentnode = currentnode->ptr_next_node;
		count++;
	}
	
}

int main()
{
    double s;
    int n, N;
    cout << "Введите количество элементов очереди: ";
    cin >> n;
    N = n;
    Queue queue;
    Queue TMPqueue;
    cin.get();
    for (int i = 1; i <= n; i++)
    {
        cout << "Введите число " << i << ": ";
        cin >> s;
        PushQueue(queue, s);
    }
    cout << endl << "Сформированая очередь " << endl;
    PrintQueue(queue);
    
    changeQueue(queue);
    
    cout << endl << "Обновлённая очередь" << endl; 
    PrintQueue(queue);
}
