#include <iostream>
using namespace std;


int main()
{
    unsigned long long n = 0;
    cin >> n;

    unsigned long long result = 1 << n;
    cout << "Result: " << result;

    return 0;
}