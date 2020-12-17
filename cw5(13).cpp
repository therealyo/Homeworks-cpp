#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
    cout << "a[0] = ";
    double result = 0, number = 0;
    cin >> number;

    int counter = 1;
    while(number != 0)
    {
        result += number;

        string elem = "";
        elem = "a[" + to_string(counter) + "] = ";
        cout << elem;
        
        int value = 0;
        cin >> value;
        number = value;

        counter++;
    }

    cout << "Result = " << result;
    return 0;
}