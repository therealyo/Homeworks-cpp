#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter numbers: ";
	double num1 = 0, num2 = 0, num3 = 0;
	cin >> num1 >> num2 >> num3;

	num1 = abs(num1);
	num2 = abs(num2);
	num3 = abs(num3);
	
	double max = 0, min = 0;

	if (num1 < num2)
	{
		if (num1 < num3)
		{
			min = num1;
			if (num2 < num3)
			{
				max = num3;
			}
			else
			{
				max = num2;
			}
		}
		else
		{
			min = num3;
			max = num2;
		}
	}
	else
	{
		if (num2 < num3)
		{
			min = num2;
			if (num1 < num3)
			{
				max = num3;
			}
			else
			{
				max = num1;
			}
		}
		else
		{
			min = num3;
			max = num1;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;

	return 0;
}