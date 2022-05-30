#include "Header.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	cout << "Введите в консоль: " << endl << endl;
	cout << "6 8 1 6 11 6 5 18 5 4 33 4 2 13 2 3 8 3 1 3 3 5 7 6 2 14" << endl;
	graph = graph_implementation();
	graph.Print();
	BestWay(Adjacency_matrix, n, dynamic_mas, result);
	return 0;
}
