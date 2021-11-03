#include <iostream>		// Äîáàâëåíèå áèáëèîòåêè iostream
using namespace std;	// Îáúÿâëåíèÿ ïðîñòðàíñòâà èìåí std

int main()	// Îáçíà÷àåì main ôóíêöèþ
{
	setlocale(LC_ALL, "Rus");
	char a, b, c, d, e;	// Ïåðåìåííûå äëÿ çíà÷åíèé âðåìåíè
	cout << "Ââåäèòå 5 ñèìâîëîâ: ";
	cin >> a >> b >> c >> d >> e;
	cout << e << d << c << b << a;
}
