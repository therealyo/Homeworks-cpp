#include <iostream>
using namespace std;

int inputRows()
{
	cout << "Input rows: ";
	unsigned int rows = 0;
	cin >> rows;
	return rows;
}

int inputColumns()
{
	cout << "Input m: ";
	unsigned int columns = 0;
	cin >> columns;
	return columns;
}

double** mulMatrix(const unsigned int rows1, const unsigned int cols1, const unsigned int rows2,const unsigned int cols2, double** matrix1, double** matrix2)
{
	double** arrayResult = new double* [rows1];
	for (int index1 = 0; index1 < cols1; ++index1)
	{
		arrayResult[index1] = new double[cols2];
		for (int index2 = 0; index2 < cols2; ++index2)
		{
			arrayResult[index1][index2] = 0;
			for (int index3 = 0; index3 < cols1; ++index3)
			{
				arrayResult[index1][index2] += matrix1[index1][index3] * matrix2[index3][index2];
			}
		}
	}
	return arrayResult;
}

double **inputArray(const unsigned int rows, const unsigned int cols)
{
	double** newArray = new double *[rows];
	for (int index1 = 0; index1 < rows; ++index1)
	{
		newArray[index1] = new double [cols];
		for (int index2 = 0; index2 < cols; ++index2)
		{
			cout << "Input array[" << index1 << "][" << index2 << "] = ";
			double element = 0;
			cin >> element;
			newArray[index1][index2] = element;
		}
	}

	return newArray;
}

void printArray(const unsigned int rows, const unsigned int cols, double **array)
{
	for (int index1 = 0; index1 < rows; ++index1)
	{
		for (int index2 = 0; index2 < cols; ++index2)
		{
			cout << array[index1][index2] << " ";
		}
		cout << endl;
	}
}

void delete2DimArray(const unsigned int rows, double **array)
{
	for (int index = 0; index < rows; ++index)
	{
		delete[] array[index];
	}
	delete[] array;
}

void deleteLength(const unsigned int len, int **array)
{
	for (int index = 0; index < len; ++index)
	{
		delete[] array[index];
	}
	delete[] array;
}

int main()
{
	cout << "Input array length: ";
	unsigned int len = 0;
	cin >> len;

	int **arrayLength = new int *[len];
	double ***array = new double **[len];
	for (int index = 0; index < len; ++index)
	{
		cout << "For matrix " << index + 1 << ": " << endl;
		unsigned int rows = inputRows();
		unsigned int columns = inputColumns();
		double **array0 = inputArray(columns, rows);
		array[index] = array0;
		arrayLength[index] = new int[2];
		arrayLength[index][0] = rows;
		arrayLength[index][1] = columns;
	}

	int check = 1;
	for (int index = 0; index < len - 1; ++index)
	{
		if (arrayLength[index][1] != arrayLength[index + 1][0])
		{
			check = 0;
		}
	}

	double** arrayResult = array[0];
	if (check == 1)
	{
		for (int index = 0; index < len-1; ++index)
		{
			unsigned int rows1 = arrayLength[index][0];
			unsigned int cols1 = arrayLength[index][1];
			unsigned int rows2 = arrayLength[index+1][0];
			unsigned int cols2 = arrayLength[index+1][1];
			arrayResult = mulMatrix(rows1, cols1, rows2, cols2, arrayResult, array[index+1]);
		}
		unsigned int rows = arrayLength[0][0];
		unsigned int cols = arrayLength[0][1];
		printArray(rows, cols, arrayResult);
	}
	else
	{
		cout << "It is impossible" << endl;
	}

	for (int index = 0; index < len; ++index)
	{
		delete2DimArray(arrayLength[index][0], array[index]);
	}
	delete[] array;

	deleteLength(len, arrayLength);

	return 0;
}
