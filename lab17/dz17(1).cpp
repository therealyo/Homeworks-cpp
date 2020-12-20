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
        if(words[i].find(" ") == -1)
        {
            string temp = words[i];
            words[i].clear();
            for(int j = 1; j < temp.length(); ++j)
            {   
                words[i].push_back(temp[j]);
            }
        }
    }

    for(int i = 0; i < words.size(); i++)
    {
        if(i > 0) {text += ' ' + words[i];}
        else {text += words[i];}
    }

    cout << text;



    return 0;
}