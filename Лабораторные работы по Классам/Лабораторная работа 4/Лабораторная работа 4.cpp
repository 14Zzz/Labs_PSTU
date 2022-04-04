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
            this -> RUB = RUB;
            this -> KOP = KOP;
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
	    
	    Money& operator=(const Money&m)
	    {
    		if (&m == this) 
    		{
    			return *this;
    		}
    		RUB = m.RUB;
    		KOP = m.KOP;
    		return *this;
    	}
    	
    	Money& operator-(const Money&m)
	    {
    		RUB = RUB - m.RUB;
    		KOP = KOP - m.KOP;
    		if (KOP >= 100)
            {
                RUB += KOP / 100;
                KOP %= 100;
            }
    		return *this;
    	}
    	
    	Money& operator+(const Money&m)
	    {
    		RUB = RUB + m.RUB;
    		KOP = KOP + m.KOP;
    		if (KOP >= 100)
            {
                RUB += KOP / 100;
                KOP %= 100;
            }
    		return *this;
    	}
    	friend ostream& operator<<(ostream& out, const Money& m);
    	friend istream& operator>>(istream& in, const Money& m);
	    ~Money()
    	{
	    	cout << "*Это деструктор уничтожил рубль, а не государство" << endl;
    	}
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

int main()
{
    setlocale(LC_ALL, "RUS");
    Money a, b, c;
    cin >> a >> b;
    c = a;
    cout << endl << "Введённая деньга 1 = " << a << endl;
    cout << endl << "Введённая деньга 2 = " << b << endl;
    
    cout << "a + b = " << a + b << endl;
    a = c;
    cout << "a - b = " << a - b << endl;
}
