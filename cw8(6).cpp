#include <iostream>
using namespace std;


int main()
{
    unsigned int summ = 0;
    unsigned int counter = 0;

    while (true)
    {
        unsigned int val = 0;
        cout << "a[" << counter << "] = ";
        cin >> val;

        if (val == 0)
        {
            break;
        }
        else
        {
            summ += val;
            counter++;
        }
    }

    cout << "Sum of entered elements = " << summ;
    return 0;
}