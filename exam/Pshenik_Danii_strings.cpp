#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
    map<char, int> symbols;
    for(int i = 97; i < 123; ++i)
    {
        symbols.insert({i, i});
    }

    for(auto i = symbols.begin(); i != symbols.end(); ++i)
    {
        cout << i->first << " " << i->second << " ";
    }
    cout << endl;

    cout << "Input string: ";
    string input;
    getline(cin, input);
    
    cout << "Input key: ";
    int key = 0;
    cin >> key;
    
    for(int i = 0; i < input.length(); ++i)
    {
        input[i] = tolower(input[i]);
    }

    for(int i = 0; i < input.length(); ++i)
    {
        for(auto j = symbols.begin(); j != symbols.end(); ++j)
        {
            if (input[i] == j->first)
            {
                if (j->second + key < 122)
                {
                    input[i] = j->second + key;
                    break;
                }
                else
                {
                    input[i] = ((j->second + 97 + key) % 122) - 1;
                    break;
                }
                
            }
        }
    }

    cout << input;

    return 0;
}