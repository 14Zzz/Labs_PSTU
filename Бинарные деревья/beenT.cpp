#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int SUM = 0;

struct point
{
	int data;
	point *left, *right;
};

point* tree = NULL;

int* mass;

void push(int a, point** t)
{
	if ((*t) == NULL)
	{
		(*t) = new point;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	push(rand() % 100, &(*t)->left);
	push(rand() % 100, &(*t)->right);
	return;
}

void print(point* t, int u)
{
	if (t == NULL) {
		return;
	}
	else
	{
		print(t->left, ++u);
		for (int i = 0; i < u; ++i) cout << "    ";
		cout << "---" << t->data << endl;
		u--;
	}
	print(t->right, ++u);
}

void SR_SUM(point* t, int u)
{
	if (t == NULL) {
		return;

	}
	else
	{
		SR_SUM(t->left, ++u);
		SUM += t->data;
		u--;
	}
	SR_SUM(t->right, ++u);
}

int Run(point* t, int*& mass, int& g)
{
	if (t != NULL)
	{
		mass[g] = t->data;
		g++;
	}
	if (t)
	{
		Run(t->left, mass, g);
		Run(t->right, mass, g);
	}

	return 0;
}

void sort(point** e, int a)
{
	if ((*e) == NULL)
	{
		(*e) = new point;
		(*e)->data = a;
		(*e)->left = (*e)->right = NULL;
		return;
	}
	if (a > (*e)->data) sort(&(*e)->left, a);
	else sort(&(*e)->right, a);
}

void free(point** tree)
{
	if (*tree != NULL)
	{
		free(&(*tree)->left);
		free(&(*tree)->right);
		delete* tree;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n = 3;
	int g = 0;
	int* mass = new int[n];

	for (int i = n; i > 0; i--)
	{
		push(rand() % 100, &tree);
	}

	cout << "Ваше дерево:\n\n\n";
	print(tree, 0);
	cout << endl;


	SR_SUM(tree, 0);
	cout << "Сумма = " << SUM << endl;
	SUM = 0;


	Run(tree, mass, g);
	free(&tree);
	tree = NULL;
	for (int i = 0; i < g; i++)
	{
		int a;
		a = mass[i];
		sort(&tree, a);
	}
	cout << "Дерево поиска:\n\n\n";
	print(tree, 0);
	cout << endl;

	return 0;
}
