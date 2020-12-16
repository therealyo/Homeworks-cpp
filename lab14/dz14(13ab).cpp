#include <iostream>
#include <string>
using namespace std;

const int MAXPERSONS = 2; 

typedef struct {
    string name;
    string sex;
    unsigned int height;

} Person;


float AvrgHeight(Person *mass, const int size, string sex)
{
    unsigned int summ = 0;
    unsigned int counter = 0;

    for(int i = 0; i < size; ++i)
    {
        if(mass[i].sex == sex)
        {
            counter++;
            summ += mass[i].height;
        }
    }

    if (counter != 0) return (summ/counter);
    else return 0;
}


Person HighestPers(Person *mass, const int size, string sex)
{
    bool male_exst = false;
    Person highest;

    for(int i = 0; i < size; ++i)
    {
        if(mass[i].sex == sex)
        {
            if(male_exst == false)
            {
                male_exst = true;
                highest = mass[i];
            }
            else
            {
                if(mass[i].height > highest.height)
                {
                    highest = mass[i];
                }
            }
            
        }
    }

    return highest;
}


int main()
{
    Person persons[MAXPERSONS];

    for(int i = 0; i < MAXPERSONS; i++)
    {
        Person prs;
        cout << "Enter name: ";
        cin >> prs.name;
        cout << "Enter sex: ";
        cin >> prs.sex;
        cout << "Enter height: ";
        cin >> prs.height;

        persons[i] = prs;
    }


    Person res = HighestPers(persons, MAXPERSONS, "man");

    cout << AvrgHeight(persons, MAXPERSONS, "woman") << endl;
    cout << res.name << " is highest man. His height is " << res.height << endl; 



    
    return 0;
}