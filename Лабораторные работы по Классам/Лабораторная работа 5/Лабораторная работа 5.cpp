#include <iostream>
#pragma once
using namespace std;

class Object

{

	public:

		virtual void Show()=0;
};

class Pair : public Object
{
  protected:
  		int first;
  		int second;

  public:
	Pair(void)
	{
		first = 0;
		second = 0;
	}

  public:
    void Show() override
    {
    	cout << first << "," << second << endl;
    }
	virtual ~Pair()
	{
	}
	
	Pair(int first, int second)
	{
		this->first = first;
		this->second = second;
	}
	
	void set(int first, int second)
	{
		this->first = first;
		this->second = second;
	}
	int getFirst(const Pair &p)
	{
		return p.first;
	}
	int getSecond(const Pair &p)
	{
		return p.second;
	}
	
	void copy(const Pair &p)
	{
		first = p.first;
		second = p.second;
	}
	friend ostream &operator<<(ostream &out, const Pair &p);
	friend istream &operator>>(ostream &in, const Pair &p);
	Pair &operator=(const Pair &p)
	{
		if (&p == this)
		{
			return *this;
		}
		first = p.first;
		second = p.second;
		return *this;
	}
	Pair operator+(const Pair& pair);
};

ostream &operator<<(ostream &out, const Pair &p)
{
	return (out << p.first << "," << p.second);
}

istream &operator>>(istream &in, Pair &p)
{
	int first;
	int second;
	cout << "Введите Pair" << endl;
	cout << "first = ";
	in >> first;
	cout << "second = ";
	in >> second;
	p.set(first, second);
	return in;
}

Pair Pair::operator+(const Pair& pair)
{
	Pair tmp;
	tmp.first = first + second;
	tmp.second = pair.first + pair.second;
	return tmp;
}

class Long : public Pair
{
	public:
			Long(const int& x, const int& y) : Pair(x,y){};
	Long operator+(const Long& L);
	Long operator-(const Long& L);
	Long operator*(const Long& L);
};

Long Long::operator+(const Long& L)
{
	Long tmp(0, 0);
	tmp.first = L.first + first;
	tmp.second= L.second + second;
	return tmp;
}
Long Long::operator-(const Long& L)
{
	Long tmp(0, 0);
	tmp.first = first - L.first;
	tmp.second= second - L.second;
	return tmp;
}
Long Long::operator*(const Long& L)
{
	Long tmp(0, 0);
	tmp.first = first * L.first;
	tmp.second= second * L.second;
	return tmp;
}
class Vector

{

	public:

			Vector(void);//конструктор без параметров

			Vector(int);//конструктор копирования

	public:

			~Vector(void);//деструктор

			void Add(Object *);//добавление элемента в вектор

			friend ostream& operator<<(ostream&out, const Vector&);//операция вывода

	private:

			Object**beg;//указатель на первый элемент вектора

			int size;//размер

			int cur;//текущая позиция

};

//конструктор без параметров

Vector::Vector(void)

{

	beg=0;

	size=0;

	cur=0;

}

//деструктор

Vector::~Vector(void)

{

	if(beg!=0)delete [] beg;

	beg=0;

}

//конструктор с параметрами

Vector::Vector(int n)

{

	beg=new Object*[n];

	cur=0;

	size=n;

}

//добавление объекта, на который указывает указатель p в вектор

void Vector::Add(Object *p)

{

	if(cur<size)

	{

		beg[cur]=p;

		cur++;

	}

}

//операция вывода

ostream& operator<<(ostream&out,const Vector&v)

{

	if(v.size==0) out<<"Empty"<<endl;

	Object **p=v.beg;//указатель на указатель типа Object

	for(int i=0;i<v.cur;i++)

	{

		(*p)->Show();//вызов метода Show() (позднее связывание)

		p++;//передвигаем указатель на следующий объект

	}

	return out;

}

int main()
{
        setlocale(LC_ALL, "rus");
	Vector v(5);

	Pair a;

	cin>>a;

	Long b(a.getFirst(a), a.getSecond(a));
	Object*p=&a;
	v.Add(p);

	p=&b;

	v.Add(p); 

	cout<<v;

}
