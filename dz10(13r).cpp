#include <iostream>
using namespace std;


bool findZero(double *array, const int size)
{
    bool include_zero = false;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] == 0)
        {
            include_zero = true;
            break;
        }
    }

    return include_zero;
}


int main()
{
    cout << "Enter size of the matrix: ";
    int rows = 0, cols = 0;
    cin >> rows >> cols;

    double **matrix = new double *[rows];


    
    for(int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cout << "Enter element: ";
            double elem = 0;
            cin >> elem;
            matrix[i][j] = elem;
        }
    }

   for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; ++i)
    {
        if (findZero(matrix[i], cols))
        {
            int rowToDelete = i;
            delete[] matrix[rowToDelete];
            double **tmp = new double *[rows - 1];
            int tmpI = 0;

            for(int i = 0; i < rows; ++i)
            {
                if(i != rowToDelete)
                    tmp[tmpI++] = matrix[i];
            }
            delete[] matrix;
            matrix = tmp;
            rows--;
        }
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    for(int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}