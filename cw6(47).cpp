#include <iostream>
#include <cmath>
using namespace std;


bool IsPrime(int num)
{
    bool prime = true;
    if(num == 2)
    {
        return true;
    }
    else
    {
        
        for(int i = 2; i < pow(num, 0.5) + 1; ++i)
        {
            if(num % i == 0)
            {
                prime = false;
                break;
            }
        }
    return prime;
    }
}

int main()
{
    cout << "Enter number: ";
    int number = 0;
    cin >> number;

    for(int i = 2; i <= number; ++i)
    {
        if(IsPrime(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}