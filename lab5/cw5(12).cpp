#include <iostream>
using namespace std;


int main()
{
    cout << "Enter number: ";
    double number = 0;
    cin >> number;

    cout << endl;

    while(1 + number != 1)
    {
        number /= 2;
    }  

    cout << "Number = " << number;
    return 0;
}