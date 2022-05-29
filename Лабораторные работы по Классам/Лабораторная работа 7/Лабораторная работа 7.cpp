#include <iostream>

using namespace std;

class Money
{
private:
	long RUB;
	int KOP;
public:
	void set(long RUB, int KOP)
	{
		if (KOP >= 100)
		{
			RUB += KOP / 100;
			KOP %= 100;
		}
		this->RUB = RUB;
		this->KOP = KOP;
	}

	void MoneyBezPar()
	{
		RUB = 100;
		KOP = 14;
	}

	void copy(const Money& money)
	{
		RUB = money.RUB;
		KOP = money.KOP;
	}

	Money& operator=(const Money& m)
	{
		if (&m == this)
		{
			return *this;
		}
		RUB = m.RUB;
		KOP = m.KOP;
		return *this;
	}

	Money& operator-(const Money& m)
	{
		RUB = RUB - m.RUB;
		KOP = KOP - m.KOP;
		if (KOP >= 100)
		{
			RUB += KOP / 100;
			KOP %= 100;
		}
		if (KOP < 0)
		{
			RUB -= 1;
			KOP += 100;
		}
		return *this;
	}

	Money& operator+(const Money& m)
	{
		RUB = RUB + m.RUB;
		KOP = KOP + m.KOP;
		if (KOP >= 100)
		{
			RUB += KOP / 100;
			KOP %= 100;
		}
		if (KOP < 0)
		{
			RUB -= 1;
			KOP += 100;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Money& m);
	friend istream& operator>>(istream& in, const Money& m);
	~Money() {}
};

ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.RUB << "," << m.KOP);
}

istream& operator>>(istream& in, Money& m)
{
	long RUB;
	int KOP;
	cout << "Введите деньгу" << endl;
	cout << "Количество рублей в деньге = "; in >> RUB;
	cout << "Количество копеек в деньге = "; in >> KOP;
	m.set(RUB, KOP);
	return in;
}

template <class T>
class Plenty
{
private:
	int size;
	T* data;
public:
	Plenty(int s, T tmp)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp;
		}
	}
	Plenty(const Plenty<T>& tmp)
	{
		size = tmp.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
	}
	~Plenty()
	{
		delete[]data;
		data = 0;
	}
	Plenty& operator=(const Plenty<T>& tmp)
	{
		if (this == &tmp)
		{
			return *this;
		}
		size = tmp.size;
		if (data != 0)
		{
			delete[]data;
		}
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
		return *this;
	}
	T& operator[](int index)
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Индекс больше размера вектора" << endl;
			return data[0];
		}
	}
	Plenty operator+(const Plenty<T> plen)
	{
		T z;
		z.set(0, 0);
		int c = 0;
		int s = this->size + plen.size;
		Plenty tmp(s, z);
		for (int i = 0; i < size; i++)
		{
			tmp.data[i] = this->data[i];
		}
		for (int i = this->size; i < s; i++)
		{
			tmp.data[i] = plen.data[c];
			c++;
		}
		return tmp;
	}
	int operator()()
	{
		return size;
	}
	friend ostream& operator<< <>(ostream& out, const Plenty<T>& tmp);
	friend istream& operator>> <>(istream& in, Plenty<T>& tmp);
};
template <class T>
ostream& operator<< <>(ostream& out, const Plenty<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.data[i] << " ";
	}
	return out;
}

template <class T>
istream& operator>> <>(istream& in, Plenty<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.data[i];
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Money t;
	t.set(10, 11);
	cout << t << endl;
	cout << "Введите 3 деньги" << endl;
	Plenty<Money>arr(3, t);
	cin >> arr;
	cout << "Множество 1 = " << arr << endl;
	Plenty<Money>a(4, t);
	cout << "Множество 2 = " << a << endl;

	cout << "Множество 1[2] = " << arr[1] << endl;
	cout << "Размер mножествa 1 = " << arr() << endl;
	arr = arr + a;
	cout << "Множество 1 + множество 2 = " << arr;
	return 0;
}
