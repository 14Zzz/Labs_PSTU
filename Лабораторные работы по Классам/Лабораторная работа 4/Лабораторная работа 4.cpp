#include <iostream>
#pragma once
using namespace std;

class Pair
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
int main()
{
	Pair A, B;
	cin >> A >> B;
	cout << "Pair A = " << A << endl;
	cout << "Pair B = " << B << endl;
	cout << "A + B = " << A + B << endl;
	Long a(A.getFirst(A), A.getSecond(A)), b(B.getFirst(B), B.getSecond(B));
	cout << "Long a = " << a << endl;
	cout << "Long b = " << b << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	return 0;
}
