#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num1, num2, num3;
	cout << "Enter numbers: ";
	cin >> num1 >> num2 >> num3;

	int res;
	res = num1 * num2 * num3;

	if ((abs(num1) < pow(2, 10)) && (abs(num2) < pow(2, 10)) && (abs(num3) < pow(2, 10)))
	{
		cout << "a) num1*num2*num3 = " << res << endl;
	}

	if ((abs(num1) < pow(2, 21)) && (fabs(num2) < pow(2, 21)) && (fabs(num3) < pow(2, 21)))
	{
		cout << "b) num1*num2*num3 = " << res << endl;
	}

	return 0;
}