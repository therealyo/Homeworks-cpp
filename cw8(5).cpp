#include <iostream>
using namespace std;


int main()
{
    unsigned int array[5];
    
    unsigned int summ_of_odd = 0;
    unsigned int summ_of_even = 0;

    for(int i = 0; i < 5; ++i)
    {
        unsigned int val = 0;
        cin >> val;

        if (val % 2 == 0)
        {
            summ_of_even += val;
        }
        else
        {
            summ_of_odd += val;
        }
        
        array[i] = val;
    }

    cout << "Sum of odd numbers = " << summ_of_odd << endl;
    cout << "Sum of even numbers = " << summ_of_even << endl;

    return 0;
}