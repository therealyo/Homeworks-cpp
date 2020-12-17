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
    int counter = 0;

    vector<string> words = split(text, ' ');

    for(int i = 0; i < words.size(); ++i)
    {
        if(words[i].find(" ") == -1)
        {
            if(words[i][0] == words[i][words[i].length() - 1])
            {
                cout << words[i] << endl;
                counter++;
            }
        }
    }

    cout << counter;
    return 0;
}