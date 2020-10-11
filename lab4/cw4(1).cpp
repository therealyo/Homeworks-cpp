#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    cout << "Enter variable: ";
    double var = 0;
    cin >> var;

    cout << "Enter amount of iterations: ";
    int amount = 0;
    cin >> amount;

    double result = sin(var);
    for(int i = 0; i < amount - 1; ++i)
    {
        result = sin(result);
    }

    cout << "Result = " << result;

    return 0;
}