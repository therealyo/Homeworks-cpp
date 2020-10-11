// task1_2.docx, 39(пункт г)
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


double Sequnce(int number)
{
    if(number == 1)
    {
        return 0;
    }
    else if(number == 2)
    {
        return 1;
    }
    else
    {
        return Sequnce(number - 1) + Sequnce(number - 2) / Factorial(number - 1); 
    }
    
}


int main()
{
    cout << "Enter amount of elements: ";
    int amount = 0;
    cin >> amount;

    long long result = 0;   

    for(int i = 1; i <= amount; ++i)
    {
        result += Factorial(i) * Sequnce(i);
    }

    cout << "Result = " << result;
    
    return 0;
}