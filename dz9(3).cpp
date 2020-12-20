#include <iostream>
using namespace std;

int main()
{
	const int rows = 2;
	const int columns = 3;
	double array[rows][columns] = { 0 };
	for (int index1 = 0; index1 < rows; ++index1)
	{
		for (int index2 = 0; index2 < columns; ++index2)
		{
			cout << "Array[" << index1 << "][" << index2 << "] = ";
			int element = 0;
			cin >> element;
			array[index1][index2] = element;
		}
	}

	return 0;
}