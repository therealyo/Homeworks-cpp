#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXLENGTH = 100;

int main()
{
	cout << "Input string: ";
	char text[MAXLENGTH];
	fgets(text, MAXLENGTH, stdin);

	int length = sizeof(text);

	int numFirstComma = 0;
	int numLastComma = 0;
	int numAllCommas = 0;

	for (int index = 0; index < length; ++index)
	{
		if (text[index] == ',')
		{
			++numAllCommas;
			numLastComma = index + 1;
			if (numAllCommas == 1)
			{
				numFirstComma = index + 1;
			}
		}
	}
	cout << "Number of the first comma: " << numFirstComma << endl;
	cout << "Number of the last comma: " << numLastComma << endl;
	cout << "Number of commas: " << numAllCommas << endl;

	return 0;
}