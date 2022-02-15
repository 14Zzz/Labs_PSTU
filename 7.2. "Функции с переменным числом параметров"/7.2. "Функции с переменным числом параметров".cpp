#include<iostream>
#include<stdarg.h>

using namespace std;

int min (int n, ...)
{
    int a;
    va_list ptr;
    va_start(ptr, n);
    int mi = va_arg(ptr, int) ;
    for (int i = 1; i < n; i++)
    {
    	a = va_arg(ptr, int);
    	if (a < mi)
    	{
    		mi = a;
    	}
    }
    va_end(ptr);
    return mi;
}

int main()
{
	cout << min(5, 9, 4, 14, 7689, 4) << endl;
    cout << min(10, -1, 14, 1, 18, -27, 26, 0, 8, 9, 50) << endl;
    cout << min(12, 65, 78, 345, 87, 34, 23, 89, 34, 45, 234, 768, 12) << endl;
    return 0;
}


