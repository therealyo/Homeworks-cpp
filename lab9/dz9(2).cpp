#include <iostream>
using namespace std;

int main()
{
	const int size = 3;
	double array[size][size] = { {1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0} };
	double arrayTransposed[size][size] = { 0 };
	for (int index1 = 0; index1 < size; ++index1)
	{
		for (int index2 = 0; index2 < size; ++index2)
		{
			arrayTransposed[index2][index1] = array[index1][index2];
		}
	}

	cout << "I: ";
	int I = 0;
	cin >> I;

	cout << "J: ";
	int J = 0;
	cin >> J;

	cout << "A: ";
	double A = 0;
	cin >> A;

	for (int index1 = 0; index1 < size; ++index1)
	{
		for (int index2 = 0; index2 < size; ++index2)
		{
			if ((index1 == I-1) && (index2 == J-1))
			{
				arrayTransposed[index1][index2] = A;
			}
		}
	}

	cout << endl << "New matrix:" << endl;
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