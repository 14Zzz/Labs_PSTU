#include <iostream>
#include <string>

using namespace std;

class Strana
{
private:
	string stolica;
	int people;
	double S;
public:
	void Dannie_o_strane(string stolica, int people, double S)
	{
		this->stolica = stolica;
		this->people = people;
		this->S = S;
	}
	
	void BezPar()
	{
		stolica = "Уададугу";
		people = 20903278;
		S = 274200;
	}
	
	void copy(const Strana& strana)
	{
		stolica = strana.stolica;
		people = strana.people;
		S = strana.S;
	}
	
	void Print()
	{
		cout << "Столица: " << stolica << endl;
		cout << "Население: " << people << endl;
		cout << "Площадь в км^2 " << S << endl;
	}
	~Strana()
	{
		cout << "Strana уничтожена" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int people;
	string stolica;
	double S;
	Strana polzovatelskaya, Bez, Ctr_C;
	cout << "Конструктор с параметрами" << endl;
	cout << "Введите название столицы: ";
	cin >> stolica;
	cout << "Введите численность населения страны: ";
	cin >> people;
	cout << "Введите площадь страны: ";
	cin >> S;
	polzovatelskaya.Dannie_o_strane(stolica,people, S);
	polzovatelskaya.Print();
	cout << endl;
	cout << "Конструктор без параметров" << endl;
	Bez.BezPar();
	Bez.Print();
	cout << endl;
	cout << "Конструктор копирования" << endl;
	Ctr_C.copy(polzovatelskaya);
	Ctr_C.Print();
	cout << endl;
	return 0;
}
