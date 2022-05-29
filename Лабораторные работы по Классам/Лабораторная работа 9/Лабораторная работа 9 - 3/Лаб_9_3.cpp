#include <iostream>
#include <string>

using namespace std;

class Error
{
public:
	virtual void what() {};
};

class IndexError : public Error
{
protected:
	string msg;
public:
	IndexError() { msg = "Ошибка индексации\n"; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error
{
protected:
	string msg;
public:
	SizeError() { msg = "Ошибка размера множества\n"; }
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError
{
protected:
	string msg_M;
public:
	MaxSizeError() {
		SizeError();
		msg_M = "Размер > MaxSize\n";
	}
	virtual void what() { cout << msg << msg_M; }
};

class EmptySizeError : public SizeError
{
protected:
	string msg_E;
public:
	EmptySizeError() {
		SizeError();
		msg_E = "Множество пусто\n";
	}
	virtual void what() { cout << msg << msg_E; }
};

class IndexError0 : public IndexError
{
protected:
	string msg_0;
public:
	IndexError0() {
		IndexError();
		msg_0 = "Индекс < 0\n";
	}
	virtual void what() { cout << msg << msg_0; }
};

class IndexErrorS : public IndexError
{
protected:
	string msg_S;
public:
	IndexErrorS() {
		IndexError();
		msg_S = "Индекс > Размер множества\n";
	}
	virtual void what() { cout << msg << msg_S; }
};

class IndexError_S : public IndexError
{
protected:
	string msg_S;
public:
	IndexError_S() {
		IndexError();
		msg_S = "Индекс < Размер множества\n";
	}
	virtual void what() { cout << msg << msg_S; }
};

const int MAX_SIZE = 20;

class Plenty
{
protected:
    int size;
    int* data;
public:
    Plenty(int size)
    {
        if (size > MAX_SIZE) throw MaxSizeError();
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
    Plenty(const Plenty& a)
    {
        size = a.size;
        data = new int[size];
        data = a.data;
    }
    Plenty& operator=(const Plenty& a)
    {
        this->size = a.size;
        this->data = a.data;
        return *this;
    }

    Plenty operator+(const Plenty plen)
    {
        int c = 0;
        int s = this->size + plen.size;
        if (s >= MAX_SIZE) throw MaxSizeError();
        Plenty tmp(s);
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

    Plenty operator++(int t)
    {
        if (size + 1 >= MAX_SIZE) throw MaxSizeError();
        Plenty tmp(size + 1);
        tmp.data[size] = t;
        for (int i = 0; i < size; i++)
        {
            tmp.data[i] = this->data[i];
        }
        data = tmp.data;
        size = tmp.size;
        return tmp;
    }

    int operator()()
    {
        return size;
    }

    int& operator[ ] (int index);

    friend istream& operator>>(istream& in, Plenty& a);
    friend ostream& operator<<(ostream& out, const Plenty& a);
};

istream& operator>>(istream& in, Plenty& a)
{
    int s;
    for (int i = 0; i < a.size; i++)
    {
        cout << "Введите элемент множества " << i + 1 << ": ";
        cin >> s;
        a.data[i] = s;
    }
    return in;
}

ostream& operator<<(ostream& out, const Plenty& a)
{
    cout << endl << "Plenty " << endl;
    cout << "size = " << a.size << endl;
    for (int i = 0; i < a.size; i++)
    {
        cout << "[" << a.data[i] << "] ";
    }
    cout << endl;
    return out;
}

int& Plenty::operator[](int index)
{
    if (index < 0) throw IndexError0();
    if (index >= size) throw IndexErrorS();
    if (index < size)
    {
        return data[index];
    }
    else
    {
        cout << "Индекс больше размера массива";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        Plenty x(4);
        Plenty y(1);
        cout << x;
        cout << "Индекс: ";
        int i;
        cin >> i;
        cout << x[i] << endl;
        cout << "Размер x: " << x() << endl;
        y = y + 3;
        cout << y;
        x++;
        cout << x;
        cout << "Размер x: " << x() << endl;
    }
    catch (Error& e)
    {
        e.what();
    }
    return 0;
}
