// task1_2.docx, 15
#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "Enter amount: ";
    int amount = 0;
    cin >> amount;
    
    cout << endl;

    string result = "1";

    for(int i = 2; i <= amount; ++i)
    {
        result += "*" + to_string(i);
    }

    cout << "n! = " << result;

    return 0;
}