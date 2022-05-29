#include <iostream>
#pragma once
using namespace std;

class Iterator
{
private:
    friend class Plenty;
    int* elem;
public:
    Iterator()
    {
        elem = 0;
    }
    Iterator(const Iterator& tmp)
    {
        elem = tmp.elem;
    }
    bool operator==(const Iterator& tmp)
    {
        return elem == tmp.elem;
    }
    bool operator!=(const Iterator& tmp)
    {
        return elem != tmp.elem;
    }
    void operator++()
    {
        ++elem;
    }
    void operator--()
    {
        --elem;
    }
    int& operator*()
    {
        return *elem;
    }
};

class Plenty
{
protected:
    int size;
    int* data;
    Iterator beg;
    Iterator end;
public:
    Plenty(int size)
    {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
        beg.elem = &data[0];
        end.elem = &data[size];
    }
    Plenty(const Plenty& a)
    {
        size = a.size;
        data = new int[size];
        data = a.data;
        beg.elem = &data[0];
        end.elem = &data[size];
    }
    Plenty& operator=(const Plenty& a)
    {
        this->size = a.size;
        this->data = a.data;
        beg.elem = &data[0];
        end.elem = &data[size];
        return *this;
    }

    Plenty operator+(const Plenty plen)
    {
        int c = 0;
        int s = this->size + plen.size;
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

    int operator()()
    {
        return size;
    }

    Iterator first()
    {
        return beg;
    }
    Iterator last()
    {
        return end;
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

ostream& operator<<(ostream & out, const Plenty & a)
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
    if (index < size)
    {
        return data[index];
    }
    else
    {
        cout << "Индекс больше размера массива";
    }
}

void main()
{
    setlocale(LC_ALL, "rus");
    Plenty a(2), b(3);
    cin >> a >> b;
    cout << a;
    cout << b;
    cout << a + b;
    a[0] = 666;
    cout << a;
    Iterator i = a.first();
    cout << *i << endl;
    ++i;
    cout << *i << endl;
}
