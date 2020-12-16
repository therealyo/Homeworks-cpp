#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "Enter your string: ";
    string text;
    getline(cin, text);

    /*
    while(text.length() % 4 != 0)
    {
        text += "\0";
    }*/

    for(int i = 0; i < text.length(); i+=4)
    {
        string str; 
        str = text[i] + text[i+1] + text[i+2] + text[i+3];

        cout << stoi(str);
    }

    return 0;
}