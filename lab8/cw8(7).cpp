#include <iostream>
using namespace std;


void InputArray(int* array, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        int val = 0;
        cin >> val;
        array[i] = val;
    }
}

void PrintArray(int* array, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}


int* SummOfArrays(const int* array1, const int* array2, const int size)
{
    int *result = new int[size];

    for(int i = 0; i < size; ++i)
    {
        result[i] = array1[i] + array2[i];
    }

    return result;
}

int ScalarProduct(const int* array1, const int* array2, const int size)
{
    int result = 0;

    for(int i = 0; i < size; ++i)
    {
        result += array1[i] * array2[i];
    }

    return result;
}

int main()
{
    cout << "enter n: ";
    int n = 0;
    cin >> n;

    int *arr1 = new int[n];
    int *arr2 = new int[n];

    int *summ = new int[n];
    int product = 0;

    InputArray(arr1, n);
    InputArray(arr2, n);

    summ = SummOfArrays(arr1, arr2, n);
    cout << "Sum of arrays = ";
    PrintArray(summ, n);

    product = ScalarProduct(arr1, arr2, n);
    cout << "Scalar product of arrays " << product << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] summ;
 
    return 0;
}