// task1.pdf, 1.1, 19(пункт б)
#include <iostream>
using namespace std;


double Derivative(double var)
{
    if(var > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    cout << "Enter variable: ";
    double variable = 0;
    cin >> variable;

    cout << endl;

    cout << Derivative(variable) << endl;
    return 0;
}