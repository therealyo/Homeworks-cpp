#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double arr[10];


    cout << "Enter values of array" << endl;
    for(int i = 0; i < 10; ++i)
    {
        double val = 0;
        cin >> val;
        arr[i] = val;
    }

    double summ = 0;

    for(int i = 0; i < 10; ++i)
    {
        if (arr[i] > exp(1))
        {
            summ += arr[i];
        }
    }

    cout << "Sum of the elements = " << summ;


    return 0;
}