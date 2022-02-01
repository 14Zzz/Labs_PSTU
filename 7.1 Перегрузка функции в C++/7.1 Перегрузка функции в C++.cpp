#include<iostream>
#include<complex>
using namespace std;

complex<double> vichet(complex<double> a,complex<double> b)   // Вычитание комплексных чисел 
{
    return a - b;
}

float vichet(float a, float b)  // Вычитание вещественных чисел
{
    return a - b;
}

int main()
{
    // Вещественные числа
    float o = 14.585, m = 75.848;
    // Комплексные числа
    complex<double> x( 7.0, 2.0 ); // x = 7 + 2i
    complex<double> y( 1.0, 4.0 ); // y = 1 + 4i
    cout << vichet(o,m) << endl;
    cout << vichet(x, y) << endl;
}
