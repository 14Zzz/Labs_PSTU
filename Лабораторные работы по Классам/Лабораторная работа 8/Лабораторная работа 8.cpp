#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmFind = 7;
const int cmQuit = 101;

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};

class Object
{
public:
	Object() {}
	virtual void Show() = 0;
	virtual void input() = 0;
	virtual ~Object() {}
	virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person()
	{
		name = "Пусто";
		age = 0;
	}
	virtual ~Person() {}
	void Show() override
	{
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age << endl;
	}
	void input() override
	{
		cout << "\nИмя: ";
		cin >> name;
		cout << "\nВозраст: ";
		cin >> age;
		cout << endl;
	}
	Person(string n, int a)
	{
		name = n;
		age = a;
	}
	Person(const Person& tmp)
	{
		name = tmp.name;
		age = tmp.age;
	}
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetName(string n)
	{
		name = n;
	}
	void SetAge(int a)
	{
		age = a;
	}
	Person& operator=(const Person& tmp)
	{
		if (&tmp == this)
		{
			return *this;
		}
		name = tmp.name;
		age = tmp.age;
		return *this;
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			switch (e.command)
			{
			case cmGet: cout << "Имя: " << GetName() << endl;
				break;
			}
		}
	}
};

class Employee : public Person
{
protected:
	float rating;
public:
	Employee() : Person()
	{
		rating = 0;
	}
	~Employee() {}
	void Show() override
	{
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age;
		cout << "\nРейтинг: " << rating;
		cout << endl;
	}
	void input() override
	{
		cout << "\nИмя: ";
		cin >> name;
		cout << "\nВозраст: ";
		cin >> age;
		cout << "\nРейтинг: ";
		cin >> rating;
	}
	Employee(string n, int a, float z, string j) : Person(n, a)
	{
		rating = z;
	}
	Employee(const Employee& tmp)
	{
		name = tmp.name;
		age = tmp.age;
		rating = tmp.rating;
	}
	float Getrating() { return rating; }
	void Setrating(float z)
	{
		rating = z;
	}
	Employee& operator=(const Employee& tmp)
	{
		if (&tmp == this) return *this;
		name = tmp.name;
		age = tmp.age;
		rating = tmp.rating;
	}
};

class List
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	List()
	{
		beg = nullptr;
		size = 0;
		cur = 0;
	}
	List(int n)
	{
		beg = new Object * [n];
		cur = 0;
		size = n;
	}
	~List()
	{
		if (beg != 0) delete[] beg;
		beg = 0;
	}
	void Add()
	{
		Object* p;
		cout << "1. Человек" << endl;
		cout << "2. Студент" << endl;
		int y;
		cin >> y;
		if (y == 1)
		{
			Person* tmp = new Person;
			tmp->input();
			p = tmp;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
		{
			if (y == 2)
			{
				Employee* tmp1 = new Employee;
				tmp1->input();
				p = tmp1;
				if (cur < size)
				{
					beg[cur] = p;
					cur++;
				}
			}
			else return;
		}
	}
	void Show()
	{
		if (cur == 0) cout << "Пусто" << endl;
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();
			p++;
		}
	}
	int operator()()
	{
		return cur;
	}
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}
	void Find(int tmp)
	{
		beg[tmp];
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			if (i == tmp - 1)
			{
				(*p)->Show();
			}
			p++;
		}
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);
				p++;
			}
		}
	}
};

class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog() : List()
	{
		EndState = 0;
	}
	~Dialog() {}
	void HandleEvent(TEvent& event)
	{
		if (event.what == evMessage)
		{
			switch (event.command)
			{
			case cmMake:
				size = event.a;
				beg = new Object * [size];
				cur = 0;
				ClearEvent(event);
				break;
			case cmAdd:
				Add();
				ClearEvent(event);
				break;
			case cmDel:
				Del();
				ClearEvent(event);
				break;
			case cmShow:
				Show();
				ClearEvent(event);
				break;
			case cmQuit:
				EndExec();
				ClearEvent(event);
				break;
			case cmFind:
				int tmp = event.a;
				Find(tmp);
				ClearEvent(event);
				break;
			}
		}
	}
	void GetEvent(TEvent& event)
	{
		string Icode = "+-s?qm";
		string s;
		string param;
		char code;
		cout << '>';
		cin >> s;
		code = s[0];
		if (Icode.find(code) >= 0)
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm': event.command = cmMake; break;
			case '+': event.command = cmAdd; break;
			case '-': event.command = cmDel; break;
			case 's': event.command = cmShow; break;
			case 'q': event.command = cmQuit; break;
			case '?': event.command = cmFind; break;
			}
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());
				event.a = A;
			}
		}
		else event.what = evNothing;
	}
	int Execute()
	{
		TEvent event;
		do {
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (!Valid());
		return EndState;
	}
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;
	}
	void EndExec()
	{
		EndState = 1;
	}
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Dialog D;
	D.Execute();
	return 0;
}
