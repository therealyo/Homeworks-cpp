// task1_2.docx, 45(пункт б)
#include <iostream>
#include <cmath>
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
        result += pow(-1, counter) * elem;
        counter++;
        elem = pow(variable, 2 * counter) / Factorial(2 * counter);
    }
    
    cout << "Result = " << result;
    
    return 0;
}