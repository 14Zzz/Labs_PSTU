#include <iostream>

using namespace std;

void HanBashn(int n, int b1, int btmp, int b2, int c[])
{
    int D = n;
    if (n != 0)
    {
        HanBashn(n - 1, b1, b2, btmp, c);
        cout << "Действие: ";
        cout << b1 << " -> " << btmp << endl;
        c[b1 - 1] -= 1;
        c[btmp - 1] += 1;
        cout << "Количество дисков на башне " << b1 << " = " << c[b1 - 1] << endl;
        cout << "Количество дисков на башне " << b2 << " = " << c[b2 - 1] << endl;
        cout << "Количество дисков на башне " << btmp << " = " << c[btmp - 1] << endl;
        cout << endl;
        HanBashn(n - 1, b2, btmp, b1, c);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество дисков: ";
    cin >> n;
    int c[n] = {n, 0, 0};
    cout << endl;
    HanBashn(n, 1, 3, 2, c);
}
