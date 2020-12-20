#include <iostream>
using namespace std;

int main()
{
	const int rows = 2;
	const int columns = 3;
	double array[rows][columns] = {0};
	for (int index1 = 0; index1 < rows; ++index1)
	{
		cout << "Array[" << index1 << "][:] = ";
		int el1 = 0, el2 = 0, el3 = 0;
		cin >> el1 >> el2 >> el3;
		array[index1][0] = el1;
		array[index1][1] = el2;
		array[index1][2] = el3;
	}

	return 0;
}