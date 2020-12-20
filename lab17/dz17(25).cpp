#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string& s, char delimiter)
{   
    string str_delimiter;
    str_delimiter.push_back(delimiter);
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    string text;
    getline(cin, text);
    vector<string> words = split(text, ' ');
    text.clear();

    for(int i = 0; i < words.size(); ++i)
    {
        if      (words[i] == "one")   {words[i] = "1";}
        else if (words[i] == "two")   {words[i] = "2";}
        else if (words[i] == "three") {words[i] = "3";}
        else if (words[i] == "four")  {words[i] = "4";}
        else if (words[i] == "five")  {words[i] = "5";}
        else if (words[i] == "six")   {words[i] = "6";}
        else if (words[i] == "seven") {words[i] = "7";}
        else if (words[i] == "eight") {words[i] = "8";}
        else if (words[i] == "nine")  {words[i] = "9";}
    }

    for(int i = 0; i < words.size(); i++)
    {
        if(i > 0) {text += ' ' + words[i];}
        else {text += words[i];}
    }

    cout << text;
    return 0;
}