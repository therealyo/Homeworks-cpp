#include <iostream>
using namespace std;

bool IsEven(int num)
{
	bool even = false;
	if (num % 2 == 0)
	{
		even = true;
	}
	return even;
}

bool By10(int num)
{
	bool divide = false;
	if (num % 10 == 0)
	{
		divide = true;
	}
	return divide;
}

bool Divideble(int num1, int num2)
{
	bool divide = false;
	if (num1 % num2 == 0)
	{
		divide = true;
	}
	return divide;
}

int main()
{
	int num1;
	cout << "Enter first number: ";
	cin >> num1;
	
	bool ans1;
	ans1 = IsEven(num1);
	cout << "a) " << ans1 << endl;

	bool ans2;
	ans2 = By10(num1);
	cout << "b) " << ans2 << endl;

	int num2;
	cout << "Enter second number: ";
	cin >> num2;

	bool ans3;
	ans3 = Divideble(num1, num2);
	cout << "c) " << ans3 << endl;

    return 0;
}