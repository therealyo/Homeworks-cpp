#include <iostream>
#include <cmath>
using namespace std;

float function(float var)
{
    return (pow(var, 3) + 4 * pow(var, 2) + var - 6);
}

int main()
{
    cout << "Enter epsilon: ";
    float epsilon = 0;
    cin >> epsilon;

    cout << "Enter a and b: ";
    float a, b = 0;
    cin >> a >> b;
    
    float previous_element = a;
    float element = previous_element - (function(previous_element) / (function(b) - function(previous_element)) *
                                        (b - previous_element));

    while (abs(element - previous_element) >= epsilon)
    {
        previous_element = element;
        element = previous_element - (function(previous_element) / (function(b) - function(previous_element)) *
                                        (b - previous_element));
    }

    cout << "Solution: " << element << endl;

    cout << function(element);

    return 0;
}
