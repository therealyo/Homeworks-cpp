#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    cout << "Enter m";
    int m = 0;
    cin >> m;

    cout << endl;

    int power = 0;

    while(pow(4, power) < m)
    {
        power++;
    }

    cout << "Power =  " << power - 1;
    return 0;
}