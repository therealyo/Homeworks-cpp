#include <iostream>
using namespace std;


void FindBiggest(int* arr, const int size)
{
    int max = arr[0];

    for(int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "Biggest element is: " << max;
}

int main()
{
    int array[5];

    for(int i = 0; i < 5; ++i)
    {
        int val = 0;
        cin >> val;
        array[i] = val;
    }

    FindBiggest(array, 5);


    return 0;
}