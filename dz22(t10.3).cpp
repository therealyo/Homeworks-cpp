#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;

vector<string> split(const string& s, char delimiter)
{   
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }

    return tokens;
}

vector<long long int> convert(vector<string>& arr)
{
    vector<long long int> result;
    for(int i = 0; i < arr.size(); ++i)
    {
        result.push_back(stoi(arr[i]));
    }

    return result;
}


int FindBiggestInSubarray(vector<long long int> array,  const int start, const int end)
{
    try
    {
        int temp = array[start];

        for(int i = start + 1; i < end; ++i)
        {
            if(array[i] > temp)
            {
                temp = array[i];
            }
        }
        if(end > array.size())
        {
            throw exception();
        }
        return temp;

    }   
    catch(const exception& e)
    {
        vector<long long int> ending;
        int remain = array.size() % (end - start);
        for(int i = array.size() - remain; i < array.size(); i++ )
        {
            ending.push_back(array[i]);
        }
        return FindBiggestInSubarray(ending, 0, ending.size());
    }
}


int main()
{
    cout << "Enter divisor: ";
    int divisor;
    int counter = 0;
    cin >> divisor;

    ifstream input_file("f.txt");
    ofstream output_file;
    output_file.open("g.txt");

    while(input_file)
    {
        vector<string> temp;
        string line;
        getline(input_file, line);
        temp = split(line, ' ');

        vector<long long int> elems = convert(temp);

        for(int i = 0; i < elems.size(); i += divisor)
        {
            output_file << FindBiggestInSubarray(elems, i, i + divisor) << endl;
        }        
    }

    return 0;
}