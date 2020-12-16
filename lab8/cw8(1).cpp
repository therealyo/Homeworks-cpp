#include <iostream>
using namespace std;


int main()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        int val = 0;
        cin >> val;
        arr[i] = val;
    }

    cout << "Enter your number: ";
    float numb = 0;
    cin >> numb;

    int counter = 0;
    
    for(int i = 0; i < 5; i++)
    {
        if (arr[i] < numb)
        {
            counter++;
        }
    }


    cout << "Amount: " << counter;

    return 0;
}