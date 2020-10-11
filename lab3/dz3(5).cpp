// task1.pdf, 1.1, 5
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    cout << "Enter variable: ";
    double x = 0;
    cin >> x;

    cout << endl;

    // Определяем переменную для знака х
    int signX = 0;
    // Условный тернарный оператор для определения значения sing(X)
    signX = (x > 0) ? 1 : (x < 0) ? -1 : 0;

    cout << "|x| = " << abs(x) << endl;
    cout << "sign(x) = " << signX << endl;
    cout << "||x| - 1| - 1 = " << abs(abs(x) - 1) - 1 << endl;
    cout << "sin(x) = " << sin(x) << endl;

    return 0;
}