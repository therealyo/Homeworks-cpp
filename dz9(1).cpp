#include <iostream>
using namespace std;

int main()
{
	const int size = 3;
	int array[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int arrayTransposed[size][size] = {0};
	for (int index1 = 0; index1 < size; ++index1)
	{
		for (int index2 = 0; index2 < size; ++index2)
		{
			arrayTransposed[index2][index1] = array[index1][index2];
		}
	}

	cout << "rows: ";
	int rows = 0;
	cin >> rows;

	cout << "columns: ";
	int columns = 0;
	cin >> columns;

	for (int index1 = 0; index1 < size; ++index1)
	{
		for (int index2 = 0; index2 < size; ++index2)
		{
			if (arrayTransposed[index1][index2] == columns)
			{
				arrayTransposed[index1][index2] = rows;
			}
		}
	}

	cout << endl
		 << "New matrix:" << endl;
	for (int index1 = 0; index1 < size; ++index1)
	{
		for (int index2 = 0; index2 < size; ++index2)
		{
			cout << arrayTransposed[index1][index2] << " ";
		}
		cout << endl;
	}

	return 0;
}