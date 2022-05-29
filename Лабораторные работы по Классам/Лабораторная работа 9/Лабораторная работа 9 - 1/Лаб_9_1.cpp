#include<iostream>
#include<ctime>
using namespace std;
int max_size = 5;

class Plenty
{
protected:
    int size;
    int* data;
public:
    Plenty(int size)
    {
        if (size > max_size) { throw 1; }
        if (size < 0) { throw 1; }
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
        if (s > max_size) { throw 4; }
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
        if (size + 1 > max_size) { throw 4; }
        Plenty tmp(size + 1);
        tmp.data[size] = t;
        for (int i = 0; i < size; i++)
        {
            tmp.data[i] = this->data[i];
        }
        data = tmp.data;
        size = tmp.size;
        if (size == 0) { throw 3; }

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
    if (index < size)
    {
        return data[index];
    }
    else
    {
        throw 2;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Максимальный размер множества = 5" << endl;
	srand(time(0));
	try
	{
        Plenty a(2);
        a[0] = 1;
        a[1] = 2;
        cout << "Множество a:";
        cout << a;
        int index;
        cout << "Введите размер множества b: ";
        cin >> index;
		Plenty b(index);
        cin >> b;
		cout << "Размер множества a: " << a() << endl;
        cout << "Размер множества b: " << b() << endl;
        cout << "b++: " << endl;
        b++;
        cout << b;
        cout << "a + b: " << endl;
		cout << a + b;
	}
	catch (int num)
	{
		cout << "Ошибка с кодом: " << num << endl;
		cout << "1 - выбранный размер множества недопустим, размер > максимально допустимого или < 0." << endl << "2 - выбранный индекс недопустим." << endl << "3 - нельзя добавить элемент, размер больше максимально допустимого" << endl << "4 - в результате действий над множествами был превышен максимальный размер множества";
	}
	return 0;
}
