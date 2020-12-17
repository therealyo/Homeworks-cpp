#include <iostream>
#include <string>
using namespace std;

typedef struct {
    unsigned int number, year;
    string month;
} Date;


int main()
{
    Date date1;
    date1.number = 10;
    date1.year = 2000;
    date1.month = "May";

    cout << date1.number << " " << date1.month << " " << date1.year << endl;
    return 0;
}