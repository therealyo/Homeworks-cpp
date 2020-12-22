#pragma once
#include <string>
#include <iostream>

class Customer
{
private:
	std::string name;
	double time;
	double sum;

public:
	Customer();
	Customer(std::string& name, double time, double sum);
	Customer(std::string& pers);
	
	std::string GetName();
	double GetTime();
	double GetSum();
	
	void SetName(std::string& name);
	void SetTime(double time);
	void SetSum(double sum);
	
	bool operator > (Customer& pers);
	bool operator < (Customer& pers);
	bool operator ==(Customer& pers);

	friend std::ostream& operator << (std::ostream& os, const Customer& pers);
	friend std::istream& operator >> (std::istream& is, Customer& cust);
	friend bool operator < (const Customer& cust1, const Customer& cust2);
};

