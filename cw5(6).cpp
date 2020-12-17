// task1_2.docx, 15
#include <iostream>
using namespace std;

int DoubleFactorial(int n)
{
    int result = 1;

    if(n % 2 == 0)
    {
        for(int i = 2; i < n + 1; i += 2)
        {
            result *= i;
        }
    }
    else
    {
        for(int i = 1; i < n + 1; i += 2)
        {
            result *= i;
        }
    }
    
    return result;
}

int main()
{
    cout << "Enter number: ";
    int number = 0;
    cin >> number;

    cout << endl;

    cout << "DoubleFactorial: " << DoubleFactorial(number) << endl;
    return 0;
}