#include <iostream>
using namespace std;


int FactorialIncrease(int n)
{
    int result = 1;

    for(int i = 1; i < n + 1; ++i)
    {
        result *= i;
    }
    return result;
}


int FactorialDecrease(int n)
{
    int result = 1;

    for(int i = n; i > 0; --i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    cout << "Enter number: ";
    int number = 0;
    cin >> number;

    cout << endl;

    cout << "FactorialIncrease: " << FactorialIncrease(number) << endl;
    cout << "FactorialDecrease: " << FactorialDecrease(number) << endl;
    return 0;
}