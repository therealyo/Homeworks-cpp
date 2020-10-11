#include <iostream>
using namespace std;

void Solutions(double a, double b, double c)
{
	double x1, x2;
	if ((a == 0) && (b == 0) && (c == 0))
	{
		cout << "infinite solution" << endl;
	}
	else if ((a == 0) && (b == 0) && (c != 0))
	{
		cout << "no solution" << endl;
	}
	else if ((a == 0) && (b != 0))
	{
		cout << "1 solution" << endl;
		x1 = -c / b;
		cout << "x1 = " << x1 << endl;
	}
	else if (a != 0)
	{
		if (b * b - 4 * a * c == 0)
		{
			cout << "1 solution" << endl;
			x1 = -b / (2 * a);
			cout << "x1 = " << x1 << endl;
		}
		else if(b * b - 4 * a * c > 0)
		{
			cout << "2 solutions" << endl;
			x1 = (-b + b * b - 4 * a * c) / (2 * a);
			cout << "x1 = " << x1 << endl;
			x2 = (-b - b * b - 4 * a * c) / (2 * a);
			cout << "x2 = " << x2 << endl;
		}
		else
		{
			cout << "no solution" << endl;
		}
		
	}
}

int main()
{
	double a = 0, b = 0, c = 0;

	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;
	
    cout << "c = ";
	cin >> c;

    Solutions(a, b, c);

	return 0;
}