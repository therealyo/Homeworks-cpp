#include <iostream>
using namespace std;




int main()
{
    cout << "Enter number of rows and columns: ";
    int row_count = 0;
    int column_count = 0;
    cin >> row_count >> column_count;

    int **matrix = new int *[row_count];
    
    for(int i = 0; i < row_count; ++i)
    {
        matrix[i] = new int[column_count];
    }

    for(int i = 0; i < row_count; ++i)
    {
        for(int j = 0; j < column_count; ++j)
        {
            int elem = 0;
            cin >> elem;
            matrix[i][j] = elem;
        }
    }

    

    for(int i = 0; i < row_count; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}