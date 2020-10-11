// task1_2.docx, 8(пункт б)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter amount of radicals: ";
    unsigned int amount = 0;
    cin >> amount;

    cout << endl;

    double sum = 0;

    for(int index = amount; index > 0; --index)
    {
        sum = pow((3 * index + sum), 0.5);
    }

    cout << "Sum = " << sum << endl;

    return 0;
}