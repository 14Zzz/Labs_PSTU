#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Кол-во путей
int n;
// Доп. массив
int** dynamic_mas;

int* result;

// матрица смежности
int*** Adjacency_matrix;

const int Predel = 100000;
int parametr;

// макс кол-во городов
const int maxSize = 20;

// Кол-во городов
int goroda;

template<class T>
class Graph
{
	vector<T> VertikList;
	vector<T> labelList;

	bool* visitedVerts = new bool[VertikList.size()];
public:
	vector<T> Getter_n(const T& vertex);

	int adjMatrix[maxSize][maxSize];
	int GetVertPos(const T& vertex);
	int Getter_kolvo_veshin();
	int Getter_kolvo_border();
	int Getter_length(const T& vertex1, const T& vertex2);

	void Way_km(const T& vertex1, const T& vertex2, int weight);
	void Add_Vertex(const T& vertex);
	void Delete_this_Vertex();
	void Print();

	bool IsEmpty();
	bool IsFull();

	Graph();
	~Graph();
};

Graph<int> graph;



void creating_variables(int***& matrix, int& n, int**& dynamic_mas, int*& result)
{
	n = goroda;
	dynamic_mas = new int* [n];

	result = new int[n];

	matrix = new int** [n];

	for (int i = 0; i <= n; i++)
	{
		dynamic_mas[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0)
			{
				matrix[i][j] = nullptr;
				continue;
			}
			matrix[i][j] = new int(graph.adjMatrix[i][j]);
		}
	}
}
// Решение задачи методом ветвей и границ
void Vet_Gran(int*** matrix, int n, int** dynamic_mas, int* path)
{
	int fist_min;
	int second_min;

	for (int l = 0; l < n; l++) // Редукция строк
	{
		for (int i = 0; i < n; i++)
		{
			int min = Predel;
			for (int j = 0; j < n; j++)
				if (matrix[i][j] && min > *matrix[i][j])
					min = *matrix[i][j];
			for (int j = 0; j < n; j++)
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}
		for (int j = 0; j < n; j++) // Редукция столбцов
		{
			int min = Predel;
			for (int i = 0; i < n; i++)
				if (matrix[i][j] && min > *matrix[i][j])
					min = *matrix[i][j];
			for (int i = 0; i < n; i++)
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}

		for (int i = 0; i < n; i++) // Происходит оценка нулевых элементов
			for (int j = 0; j < n; j++)
				dynamic_mas[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && !*matrix[i][j])
				{
					fist_min = Predel;
					second_min = Predel;

					for (int l = 0; l < n; l++)
						if (l != i && matrix[l][j] && fist_min > *matrix[l][j])
							fist_min = *matrix[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && matrix[i][l] && second_min > *matrix[i][l])
							second_min = *matrix[i][l];

					dynamic_mas[i][j] = fist_min + second_min;
				}
			}

		int waste = 0, line_i = 0, column_j = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] && waste < dynamic_mas[i][j])
				{
					waste = dynamic_mas[i][j];
					line_i = i;
					column_j = j;
				}
		path[line_i] = column_j;

		for (int i = 0; i < n; i++)
			matrix[i][column_j] = nullptr;

		for (int i = 0; i < n; i++)
			matrix[line_i][i] = nullptr;

		matrix[column_j][line_i] = nullptr;
	}
}

//Граф
Graph<int> graph_implementation()
{
	Graph<int> graph;
	int amountEdges, sourceVertex, targetVertex, edgeWeight;
	cin >> goroda;
	while (goroda < 0)
	{
		cin >> goroda;
	}
	cin >> amountEdges;
	while (amountEdges < 0)
	{
		cin >> amountEdges;
	}

	for (int i = 1; i <= goroda; ++i) // проход до количества городов
	{
		int* vertPtr = &i;
		graph.Add_Vertex(*vertPtr);
	}

	for (int i = 0; i < amountEdges; ++i)
	{
		cin >> sourceVertex;
		int* sourceVertPtr = &sourceVertex;
		cin >> targetVertex;
		int* targetVertPtr = &targetVertex;

		cin >> edgeWeight;
		while (edgeWeight <= 0)
		{
		}
		graph.Way_km(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	return graph;
}

void BestWay(int*** matrix, int n, int** dynamic_mas, int* result)
{
	creating_variables(matrix, n, dynamic_mas, result);
	Vet_Gran(matrix, n, dynamic_mas, result);
	int s = 0;
	int j;
	for (int i = 0; i < n; i++)
	{
		j = result[i];
		s += graph.adjMatrix[i][j];
	}
	cout << endl << "Лучший путь: ";
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;
				j = result[i];
				temp = j + 1;
				if (temp > 0)
				{
					cout << " -> " << temp;
					l++;
				}
			}
		}
	}
	cout << endl << "\nПуть равен: " << s << endl;
}


template<class T>
vector<T> Graph<T>::Getter_n(const T& vertex)
{
	vector<T> nbrsList;
	int vertPos = this->GetVertPos(vertex);
	if (vertPos != (-1))
	{

		for (int i = 0, VertikListSize = this->VertikList.size(); i < VertikListSize; ++i)
		{
			if (this->adjMatrix[vertPos][i] != 0 && this->adjMatrix[i][vertPos] != 0)
				nbrsList.push_back(this->VertikList[i]);
		}
	}
	return nbrsList;
}



template<class T>
void Graph<T>::Add_Vertex(const T& vertex) // добавление вершины
{
	if (!this->IsFull())
	{
		this->VertikList.push_back(vertex);
	}
	else
	{
		cout << "Граф заполнен. Нужно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Delete_this_Vertex() // удаление города
{
	this->VertikList.pop_back();
}


template<class T>
int Graph<T>::Getter_kolvo_border() // количество границ
{
	int amount = 0;
	if (!this->IsEmpty())
	{
		for (int i = 0, VertikListSize = this->VertikList.size(); i < VertikListSize; ++i)
		{
			for (int j = 0; j < VertikListSize; ++j)
			{
				if (this->adjMatrix[i][j] == this->adjMatrix[j][i] && this->adjMatrix[i][j] != 0)
					amount += 1;
			}
		}
		return (amount / 2);
	}
	else
		return 0;
}

template<class T>
int Graph<T>::Getter_length(const T& vertex1, const T& vertex2) // получение длины пути
{
	if (!this->IsEmpty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::Getter_kolvo_veshin() // получение количества городов
{
	return this->VertikList.size();
}

template<class T>
bool Graph<T>::IsEmpty()
{
	if (this->VertikList.size() != 0)
		return false;
	else
		return true;
}

template<class T>
bool Graph<T>::IsFull() // Заполнен
{
	return (VertikList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex) // получение позиции вершины
{
	for (int i = 0; i < this->VertikList.size(); ++i)
	{
		if (this->VertikList[i] == vertex)
			return i;
	}
	return -1;
}

template<class T>
Graph<T>::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{
}


// Длина пути
template<class T>
void Graph<T>::Way_km(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0 && this->adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << endl << "Переопределяем длину данного пути " << endl << endl;
			if (weight < 0) { cout << endl << "Длина добавляемого пути не может быть отрицательной велечиной" << endl; return; }
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
			return;
		}
		else
		{
			if (weight <= 0) { cout << endl << "Длина добавляемого пути должна быть больше нуля" << endl; return; }
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
}

template<class T>
void Graph<T>::Print() // вывод матрицы смежности
{
	if (!this->IsEmpty()) // если не пусто
	{
		cout << endl << "Матрица смежности: " << endl;
		for (int i = 0, VertikListSize = this->VertikList.size(); i < VertikListSize; ++i)
		{
			cout << this->VertikList[i] << " ";
			for (int j = 0; j < VertikListSize; ++j)
			{
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}

	}

}
