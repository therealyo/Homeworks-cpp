#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;


int main()
{
    ifstream input_file("points.txt");
    ofstream output_file("lines.txt");
    map<double, string> points;

    while(input_file)
    {
        string line;
        getline(input_file, line);

        if(line != "")
        {
            string key;
            double weight;

            int index_open_parentheses = line.find("(");
            int index_closing_parentheses = line.find(")");
            int index_comma = line.find(",");
            int index_colon = line.find(":");

            key = line.substr(index_open_parentheses + 1, index_closing_parentheses - 1);
            double first_coord = stod(line.substr(index_open_parentheses + 1, index_comma - 1));
            double second_coord = stod(line.substr(index_comma + 1, index_closing_parentheses - 1));
            double mass = stod(line.substr(index_colon + 2));

            weight = mass * (first_coord + second_coord);

            points.insert({weight, key});
        }
        else { break; }
    }

    for(auto i = points.rbegin(); i != points.rend(); ++i)
    {
        string point1;
        point1.push_back('(');
        point1 += i->second;
        point1.push_back(')');

        for(auto j = ++i; j != points.rend(); ++j)
        {
            string point2;
            point2.push_back('(');
            point2 += j->second;
            point2.push_back(')');

            output_file << "Line: " << point1 << " - " << point2 << endl;
        }
    }

    return 0;
}