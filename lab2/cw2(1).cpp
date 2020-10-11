#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;

	int _1, _10, _100;
	_100 = number / 100;
	_10 = (number % 100) / 10;
	_1 = number % 10;

	cout << "1)" << number << " = " << "100*" << _100 << " + " << "10*" << _10 << " + " << _1 << endl;

	int summ;
	summ = _100 + _10 + _1;

	cout << "2)" << summ << endl;

	int result;
	result = _1 * 100 + _10 * 10 + _100;

	cout << "3)" << result << endl;

	return 0;
}