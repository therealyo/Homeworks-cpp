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
	Customer(); // Коструктор за замовчуванням
	Customer(std::string& name, double time, double sum); // Конструктор для вводу даних
	Customer(std::string& pers); // Конструктор для конвертації рядку у об'єкт класу
	
	std::string GetName(); // методи геттери
	double GetTime();
	double GetSum();
	
	void SetName(std::string& name); // методи сеттери
	void SetTime(double time);
	void SetSum(double sum);
	
	bool operator > (Customer& pers); // перевантаження булевих операторів
	bool operator < (Customer& pers);
	bool operator ==(Customer& pers);

	friend std::ostream& operator << (std::ostream& os, const Customer& pers); // перевантаження потоку виводу
	friend std::istream& operator >> (std::istream& is, Customer& cust); // перевантаження потоку вводу
	friend bool operator < (const Customer& cust1, const Customer& cust2); // булева функція порівняння
};

