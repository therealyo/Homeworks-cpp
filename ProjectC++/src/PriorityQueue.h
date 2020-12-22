#pragma once
#include <queue>
#include <iostream>
#include <vector>
#include "Customer.h"
using namespace std;

inline bool operator < (const Customer& cust1, const Customer& cust2)
{
	return cust1.time > cust2.time;
}

class PriorityQueue
{
private:
	priority_queue<Customer> customers;

public:
	PriorityQueue();
	PriorityQueue(unsigned int size);
	PriorityQueue(const char mode[]);
	PriorityQueue(vector<Customer>& vect);
	PriorityQueue(Customer* arr, const int size);
	PriorityQueue(priority_queue<Customer>& custs);

	priority_queue<Customer> GetQueue();

	PriorityQueue intersect(PriorityQueue& other);
	PriorityQueue copy();
	
	void swap(unsigned int first_index, unsigned int second_index);
	void add_queue(PriorityQueue other);
	void add(Customer& cust);
	void pop();
	Customer top();
	Customer get(unsigned int index);
	
	
	friend ostream& operator << (ostream& os, PriorityQueue& queue);
	friend ofstream& operator << (ofstream& ofs, PriorityQueue& queue);

};


