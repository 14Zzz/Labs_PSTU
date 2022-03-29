#include <iostream>

using namespace std;

class Yravnenie
{
private:
	double A;
	double B;
	double y;
public:
    void Parametri_yravnenia(double A, double B, double y)
	{
		this->A = A;
		this->B = B;
		this->y = y;
	}
	
	void root()
	{
		if (A == 0 && y == B)
		{
			cout << "Уравнение имеет бесконечное множество решений";
		}
		else if(A == 0 && y != B)
		{
			cout << "Уравнение нн имеет решений";
		}
		else 
		{
			cout << "Значение x = " << (y-B) / A;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Yravnenie yravnenie;
	double A, B, y;
	cout << "Программа вычисляет корень линейного уравнения вида y = A*x + B" << endl;
	cout << "Введите коэфицент A = ";
	cin >> A;
	cout << "Введите коэфицент B = ";
	cin >> B;
	cout << "Введите значение уравнения y = ";
	cin >> y;
	yravnenie.Parametri_yravnenia(A, B, y);
	yravnenie.root();
	return 0;
}
