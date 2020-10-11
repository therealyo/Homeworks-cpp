// task1_2.docx, 19(пункт д)
#include <iostream>
using namespace std;


// Вычисляем числитель
double GetNominator(int var, int num)
{
    long long int summ = 1;
    for(int i = 0; i < 2 * num; ++i)
    {
        summ *= var;
    }

    return summ;
}

// Вычисляем знаменатель 
double GetDenominator(int num)
{
    long long int summ = 1;
    for(int i = 1; i < (2 * num) + 1; ++i)
    {
        summ *= i;
    }

    return summ;
}

int main()
{
    cout << "Введите переменную x: ";
    int variable = 0;
    cin >> variable;

    cout << endl;

    cout << "Enter number of the element of the sequence: ";
    int number = 0;
    cin >> number;

    cout << endl;

    double nominator = GetNominator(variable, number);
    double denominator = GetDenominator(number);

    cout << nominator << endl;
    cout << denominator << endl;

    double result = nominator / denominator;

    cout << "Result = " << result;
    return 0;
}