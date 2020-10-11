#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "num1 = ";
	cin >> num1;
	cout << "num2 = ";
	cin >> num2;

	int max, min;

	if (num1 < num2)
	{
		max = num2;
		min = num1;
	}
	else
	{
		max = num1;
		min = num2;
	}

	cout << "max = " << max << endl;
	cout << "min = " << min << endl;

	return 0;
}