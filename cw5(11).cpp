// task1_2.docx, 15
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    cout << "Enter number: ";
    int number = 0;
    cin >> number; 

    cout << endl;

    int power = 0;

    while(pow(2, power) < number)
    {
        power++;
    }

    cout << "Number = " << pow(2, power);
    return 0;
}