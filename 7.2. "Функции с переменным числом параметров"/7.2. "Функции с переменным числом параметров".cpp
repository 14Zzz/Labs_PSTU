#include<iostream>

using namespace std;

int min (int n, int first, ...)
{
    int* ptr = &first;
    int mi = *ptr;
    for (n; n != 0; n--)    // Можно while (n--)
    {
        if (mi > *ptr)
        {
            mi = *ptr;
        }
        ptr += 2;   // int = 2 байта => +2 на сдвиг??
    }
    return mi;
}


int main()
{
    cout << min(5, 9, 4, 14, 7689, 4) << endl;
    cout << min(10, -1, 14, 1, 18, -27, 26, 0, 8, 9, 50) << endl;
    cout << min(12, 65, 78, 345, 87, 34, 23, 89, 34, 45, 234, 768, 12) << endl;
    return 0;
}
