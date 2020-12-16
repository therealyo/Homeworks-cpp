#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int MAXLENGTH = 100;

int main()
{
	cout << "Input string: ";
	char text[MAXLENGTH];
	fgets(text, MAXLENGTH, stdin);

	int length = strlen(text);
    int counter = 0;

    for(int i = 0; i < length; ++i)
    {
        cout << text[i];
    }

    for(int i = 0; i < length; ++i)
    {
        counter++;

        if(text[i] == ' ')
        {
            counter--;
            continue;
        }

        if (text[i] == ',' || text[i] == '!' || text[i] == '?')
        {
            for(int k = counter; k >= 1; --k)
            {
                cout << text[i - k + 1];
            }
            cout << endl;

            counter = 0;
        }

        if (counter == 6)
        {
            for(int k = counter; k >= 1; --k)
            {
                cout << text[i - k + 1];
            }
            cout << endl;
            counter = 0;
        }

    }

    return 0;
}