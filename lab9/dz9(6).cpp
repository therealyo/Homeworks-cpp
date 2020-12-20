#include <iostream>
using namespace std;

int main()
{
	const int rows = 2;
	const int columns = 3;
	int array[rows][columns] = { 0 };
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

	cout << "Input variable: ";
	int variable = 0;
	cin >> variable;

	int result = 0;
	for (int index1 = 0; index1 < rows; ++index1)
	{
		for (int index2 = 0; index2 < columns; ++index2)
		{
			if ((index1 - index2) == variable)
			{
				result += array[index1][index2];
			}
		}
	}
	cout << "Result: " << result << endl;

	return 0;
}