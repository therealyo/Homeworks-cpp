#include <iostream>
#include <cmath>
using namespace std;


int main()
{   
    cout << "Enter variable: ";
    double variable = 0;
    cin >> variable;

    cout << endl;

    cout << "Enter power";
    int power;
    cin >> power;

    cout << endl;

    double result = 0;
    for(int i = 0; i < power + 1; ++i)
    {
        result += pow(variable, i);
    }

    cout << "Result = " << result;
    return 0;
}