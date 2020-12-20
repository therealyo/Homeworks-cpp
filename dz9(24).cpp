#include <iostream>
using namespace std;

void Swap(int *arr, const int size)
{
    for(int i = 0; i < (size - 1) / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}


int main()
{
    int size = 0;

    while (true)
    {
        cout << "Enter size(odd number): ";
        cin >> size;
        
        if (size % 2 == 0)
        {
            cout << "Enter odd number!";
            cin >> size;
            continue;
        }
        else
        {
            break;
        }
    }

    int **matrix = new int *[size];
    
    for(int i = 0; i < size; ++i)
    {
        matrix[i] = new int[size];
    }

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            int elem = 0;
            cin >> elem;
            matrix[i][j] = elem;
        }
    }

    for(int i = 0; i < size; ++i)
    {
        Swap(matrix[i], size);
    }

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    for(int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}