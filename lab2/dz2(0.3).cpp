// task0.pdf, 0.3, 6(пункт з)
#include <iostream>
#include <cmath>
using namespace std;


double Func(double var, double koef)
{
    return var / pow((1 + koef * pow(var, 2)), 1/2);
}

double Derivative(double var, double koef)
{
    return pow((koef * var * var + 1), -1.5);
}

int main()
{
    cout << "Enter Variable: ";
    double variable = 0;
    cin >> variable;

    cout << endl;

    cout << "Enter coef: ";
    double alpha = 0;
    cin >> alpha;

    cout << endl;

    cout << "Function result = " << Func(variable, alpha) << endl;
    cout << "Derivative result = " << Derivative(variable, alpha) << endl;

    return 0;
}