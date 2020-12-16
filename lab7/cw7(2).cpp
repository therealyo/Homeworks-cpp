#include <iostream>
using namespace std;


int main()
{
    int result = 0;
    cout << "Enter n: ";
    cin >> result;

    unsigned int k = 0;
    cout << "Enter k: ";
    cin >> k;

    unsigned int temp = 1 << k;

    result = result | temp;
    cout << result;   
    return 0;
}