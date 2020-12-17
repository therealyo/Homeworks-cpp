#include <iostream>
#include <string>
using namespace std;


string InverseMessage(string str)
{
    string res;

    for(int i = str.length() - 1; i >= 0; --i)
    {
        res.push_back(str[i]);
    }

    return res;
}

void InverseMessage(string *str_pointer)
{
    for(int i = 0; i < ((*str_pointer).length() / 2); ++i)
    {
        char temp = (*str_pointer)[i]; 
        (*str_pointer)[i] = (*str_pointer)[(*str_pointer).length() - 1 - i];
        (*str_pointer)[(*str_pointer).length() - 1 - i] = temp;
    }
}

int main()
{
    string text;
    getline(cin, text);

    cout << InverseMessage(text) << endl;
    InverseMessage(&text);
    cout << text << endl;

    return 0;
}