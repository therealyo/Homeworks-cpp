#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
using namespace std;

const float PRICEPERRANGE = 14.8822;

vector<string> split(const string& s, char delimiter)
{   
    string str_delimiter;
    str_delimiter.push_back(delimiter);
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }

    return tokens;
}

class Person 
{
protected:
    string name;
    unsigned int byyear;

public:

    void input()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> byyear;
    }

    void print()
    {
        cout << "Name: " << name << ", "  
             << "Age:  " << byyear;
    }
};

class Passenger : public Person 
{
private:
    string departure;
    string arrival;
    double length;
    double cost = 0;  

public:
    Passenger(string& name, unsigned int year, string depart, string arriv)
    {
        this->name = name;
        this->byyear = year;
        this->departure = depart;
        this->arrival = arriv;
    }

    void input()
    {
        Person::input();
        cout << "Enter departure place: ";
        cin >> departure;
        cout << "Enter arrival place: ";
        cin >> arrival;
    }

    void print()
    {
        if (cost == 0)
        {
            Person::print();
            cout << ", " << departure << ", " << arrival;
        }
        else
        {
            Person::print();
            cout << ", " << "Departure place: " << departure << ", " 
                    << "Arrival place: " << arrival << ", " 
                    << "Price of the travel: " << cost << endl;
        }
        
    }

    void SetDeparture(string& dep)
    {
        departure = dep;
    }

    void SetArrival(string& arr)
    {
        arrival = arr;
    }

    void SetName(string& nm)
    {
        name = nm;
    }

    void SetYear(unsigned int yr)
    {
        byyear = yr;
    }


    string GetDeparture()
    {
        return departure;
    }

    string GetArrival()
    {
        return arrival;
    }

    double GetCost()
    {
        return CountCost();
    }

    double CountCost()
    {
        double cost = this->length * PRICEPERRANGE;
        return cost;
    }

    void SetLength(tuple<string, string, double> &route)
    {
        if(this->departure == get<0>(route) && this->arrival == get<1>(route))
        {
            this->length = get<2>(route);
            this->cost = this->CountCost();
        }
        else
        {
            return;
        }
        
    }
};


int main()
{
    vector< tuple<string, string, double> >  routes;

    ifstream route_file("routes.txt");

    while(route_file)
    {
        string line;
        getline(route_file, line);
        if (line != "")
        {   
            vector<string> temp = split(line, ' ');
            tuple<string, string, double> route = make_tuple(temp[0], temp[1], stod(temp[2]));
            routes.push_back({temp[0], temp[1], stod(temp[2])});
        }
        else { break; }
        
    }

    vector< Passenger > passengers;

    ifstream passenger_file("passengers.txt");

    while(passenger_file)
    {
        string line;
        getline(passenger_file, line);
        if(line != "")
        {
            vector<string> temp = split(line, ' ');
            Passenger pas(temp[0], stoi(temp[1]), temp[2], temp[3]);
            passengers.push_back(pas);
        }
        else {break;}
    }
    
    for(int i = 0; i < passengers.size(); ++i)
    {
        for(int j = 0; j < routes.size(); ++j)
        {
            passengers[i].SetLength(routes[j]);
        }
    }

    for(int i = 0; i < passengers.size(); ++i)
    {
        passengers[i].print();
    }
    
    

    return 0;
}