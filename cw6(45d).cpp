#include <iostream>
using namespace std;


double Factorial(int number)
{
    double result = 1;
    for(int i = 1; i < number + 1; ++i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    double epsilon = 0, variable = 0;
    
    cout << "Enter epsilon: ";
    cin >> epsilon;
    
    cout << endl;
    
    cout << "Enter variable: ";
    cin >> variable;

    double elem = 1, result = 0;
    int counter = 0;

    while(elem > epsilon)
    {
        result += elem;
        counter++;
        elem = pow(variable, counter) / Factorial(counter);
    }
    
    cout << "Result = " << result;
    
    return 0;
    return 0;
}