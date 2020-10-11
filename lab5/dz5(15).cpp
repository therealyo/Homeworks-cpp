// task1_2.docx, 15
#include <iostream>
using namespace std;


int main()
{
    cout << "Enter first element(> 0): ";
    int var = 0, counter = 0;
    cin >> var;

    cout << endl;

    while(var != 0)
    {
        int nextElem = 0;
        cin >> nextElem;

        if(var * nextElem < 0)
        {
            counter++;
        }

        var = nextElem;
    }

    cout << counter;
    return 0;
}