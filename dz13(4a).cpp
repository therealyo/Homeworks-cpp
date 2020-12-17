#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file1;
	file1.open("symbols.txt");
	string str;
	file1 >> str;
	file1.close();

	cout << "Input symbol: ";
	string lastSymbol;
	cin >> lastSymbol;

	str += lastSymbol;

	ofstream file2;
	file2.open("symbols.txt");
	file2 << str;
	file2.close();

	return 0;
}