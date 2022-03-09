#include <iostream>
#include <fstream>
#include <string>
#include <shlobj_core.h>
#pragma warning(disable : 4996)
using namespace std;

using namespace std;

struct Node
{
	char data;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;
};

void pushBack(List& list, char& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
	}
	else
	{
		list.tailnode->ptr_next = newnode;
		list.tailnode = newnode;
	}
}

void printList(List& list)
{
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

void addList(List& list, int D)
{
	Node* newnode = new Node;
	char data;
	int count = 1;
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		if (count == D)
		{
			cout << "Введите символ, который хотите добавить: ";
			cin >> data;
			newnode->data = data;
			currentnode->data = newnode->data;
		}
		currentnode = currentnode->ptr_next;
		count++;
	}
}

int main()
{
	string k = "/[[SPAMTON]].txt";
	std::string desktopPath = std::string(getenv("USERPROFILE")) + "\\Desktop";
	desktopPath = desktopPath + k;
	std::ofstream o(desktopPath);

	o << "Если вы это читаете, значит в вашу [[СЕТЬ]] уже проникло [[ВОЛШЕБСТВО]]\n" << std::endl;
	char a;
	setlocale(LC_ALL, "Russian");
	List list;
	int n, D;
	cout << "Введите размер списка: ";
	cin >> n;
	for (int i = 65; i <= n + 64; i++)
	{
		a = (char)i;
		pushBack(list, a);
	}
	cout << "Изначальный список" << endl;
	printList(list);
	cout << endl;
	cout << "Введите номер элемента, который нужно заменить: ";
	cin >> D;
	addList(list, D);
	cout << "Финальный список" << endl;
	printList(list);
	return 0;
}
