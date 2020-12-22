#include "PriorityQueue.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue()
{
}

PriorityQueue::PriorityQueue(unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		Customer cust;
		cin >> cust;
		cin.ignore();
		customers.push(cust);
	}
}

PriorityQueue::PriorityQueue(const char mode[])
{
	try
	{
		if (mode == "console")
		{
			cout << "Enter size of the queue: ";
			unsigned int size;
			cin >> size;
			cin.ignore();
			for (int i = 0; i < size; ++i)
			{
				Customer cust;
				cin >> cust;
				customers.push(cust);
				cin.ignore();
			}
			
		}
		else if (mode == "file")
		{
			cout << "Enter name of the file: ";
			string file_name;
			getline(cin, file_name);

			ifstream input_file(file_name);
			while (input_file)
			{
				string line;
				getline(input_file, line);
				if (line != "")
				{
					Customer cust(line);
					customers.push(cust);
				}
				else { break; }
			}
		}
		else
		{
			try
			{
				ifstream input_file(mode);
				while (input_file)
				{
					string line;
					getline(input_file, line);
					if (line != "")
					{
						Customer cust(line);
						customers.push(cust);
					}
					else { break; }
				}
			}
			catch (const exception& e)
			{

			}
		}
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

PriorityQueue::PriorityQueue(vector<Customer>& vect)
{
	for (int i = 0; i < vect.size(); ++i)
	{
		customers.push(vect[i]);
	}
}

PriorityQueue::PriorityQueue(Customer* arr, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		customers.push(arr[i]);
	}
}

PriorityQueue::PriorityQueue(priority_queue<Customer>& custs)
{
	this->customers = custs;
}

priority_queue<Customer> PriorityQueue::GetQueue()
{
	return this->customers;
}

PriorityQueue PriorityQueue::intersect(PriorityQueue& other)
{
	vector<Customer> temp, q1, q2;
	PriorityQueue copy1 = this->copy();
	PriorityQueue copy2 = other.copy();

	while (!copy1.GetQueue().empty())
	{
		Customer cust1 = copy1.top();
		copy1.pop();
		q1.push_back(cust1);
	}
	while (!copy2.GetQueue().empty())
	{
		Customer cust2 = copy2.top();
		copy2.pop();
		q2.push_back(cust2);
	}

	for (int i = 0; i < q1.size(); ++i)
	{
		for (int j = 0; j < q2.size(); ++j)
		{
			if (q1[i] == q2[j])
			{
				temp.push_back(q1[i]);
			}
		}
	}

	PriorityQueue res(temp);
	return res;
}

void PriorityQueue::swap(unsigned int first_index, unsigned int second_index)
{
	vector<Customer> vect;

	while (!this->customers.empty())
	{
		Customer cust = this->top();
		this->pop();
		vect.push_back(cust);
	}
	try
	{
		Customer tpcust = vect[first_index];
		vect[first_index].SetTime(vect[second_index].GetTime());
		vect[second_index].SetTime(tpcust.GetTime());

		for (int i = 0; i < vect.size(); ++i)
		{
			this->add(vect[i]);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
}

PriorityQueue PriorityQueue::copy()
{
	PriorityQueue res(this->customers);
	return res;
}

void PriorityQueue::add_queue(PriorityQueue other)
{
	while (!other.GetQueue().empty())
	{
		Customer cust = other.top();
		this->customers.push(cust);
		other.pop();
	}
}

void PriorityQueue::add(Customer& cust)
{
	this->customers.push(cust);
}

Customer PriorityQueue::top()
{
	Customer cust = this->customers.top();
	return cust;
}

Customer PriorityQueue::get(unsigned int index)
{
	PriorityQueue temp = this->copy();
	Customer res;
	for (int i = 0; i <= index; ++i)
	{
		res = temp.top();
		temp.pop();
	}

	return res;
}

void PriorityQueue::pop()
{
	this->customers.pop();
}


ostream& operator<<(ostream& os, PriorityQueue& q)
{
	PriorityQueue temp = q.copy();
	while (!temp.GetQueue().empty())
	{
		os << temp.top();
		temp.pop();
	}
	os << endl;

	return os;
}

ofstream& operator<<(ofstream& ofs, PriorityQueue& q)
{
	while (!q.GetQueue().empty())
	{
		ofs << q.top();
		q.pop();
	}
	ofs << endl;

	cout << "Successful!" << endl;

	return ofs;
}
