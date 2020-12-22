#include "Customer.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
using namespace std;


vector<string> split(const string& s, char delimiter)
{
    // Функція, яка заданий рядок перетворює у вектор рядків, розділяючи рядок по заданому символу
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

Customer::Customer()
{
    this->name = "";
    this->time = 0;
    this->sum = 0;
}

Customer::Customer(std::string& name, double time, double sum)
{
    // Конструктор класу Customer
    this->SetName(name);
    this->SetTime(time);
    this->SetSum(sum);

}

Customer::Customer(string& cust)
{
    // Конструктор класу Customer, який перетворює строку формату Name, Time, Sum у об'єкт класу Customer
    vector<string> temp = split(cust, ',');

    string name = temp[0];
    double time = stod(temp[1]); 
    double sum  = stod(temp[2]);

    this->SetName(name);
    this->SetTime(time);
    this->SetSum(sum);

}

string Customer::GetName()
{
    return this->name;
}

double Customer::GetTime()
{
    return this->time;
}

double Customer::GetSum()
{
    return this->sum;
}

void Customer::SetName(std::string& name)
{
    this->name = name;
}

void Customer::SetTime(double time)
{
    try
    {
        if (time > 0) { this->time = time; }
        else { throw exception("Entered negative time"); }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

void Customer::SetSum(double sum)
{
    try
    {
        if (sum > 0) { this->sum = sum; }
        else { throw exception("Entered negative sum"); }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

// Перевантаження логічних операторів
bool Customer::operator>(Customer& pers)
{
    return this->time > pers.GetTime();
}

bool Customer::operator<(Customer& pers)
{
    return this->time < pers.GetTime();
}

bool Customer::operator==(Customer& pers)
{
    return (((*this).name) == pers.GetName() && ((*this).time == pers.GetTime()) && ((*this).sum == pers.GetSum()));
}

ostream& operator<<(ostream& os, const Customer& pers)
{
    // Перевантаження оператору потокового виводу
    os << pers.name << ", " << pers.time << ", " << pers.sum << endl;
    return os;
}

istream& operator >> (istream& is, Customer& cust)
{
    // Перевантаження оператору потокового вводу
    cout << "Enter name: ";
    getline(is, cust.name);
    cout << "Enter Waiting time: ";
    is >> cust.time;
    cout << "Enter sum to pay: ";
    is >> cust.sum;
    return is;
}
