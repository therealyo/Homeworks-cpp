#include "tests.h"
using namespace std;

void testingConsoleInput()
{
	cout << "Test console input of constant size: " << endl;
	PriorityQueue pq(2);
	cout << pq << endl;
}

void testingAddingElement()
{
	cout << "Testing adding element function: " << endl;
	Customer cust;
	cin >> cust;
	PriorityQueue pq("../src/queue1.txt");
	pq.add(cust);
	cout << pq << endl;
}

void testingTopFunction()
{
	cout << "Testing top function: " << endl;
	PriorityQueue pq("../src/queue1.txt");
	Customer temp = pq.top();
	cout << temp << endl;
}

void testingPopFunctuin()
{
	cout << "Testing pop function:" << endl;
	PriorityQueue pq("../src/queue1.txt");
	pq.pop();
	cout << pq << endl;
}

void testingSwapFunction()
{
	cout << "Testing swap function: " << endl;
	PriorityQueue pq("../src/queue1.txt");
	pq.swap(0, 1);
	cout << pq << endl;
}

void testingAddQueueFunction()
{
	cout << "Testing adding queue function: " << endl;
	PriorityQueue pq1("../src/queue1.txt");
	PriorityQueue pq2("../src/queue2.txt");
	pq1.add_queue(pq2);
	cout << pq1 << endl;
}

void testingIntersectFunction()
{
	cout << "Testing intersect function: " << endl;
	PriorityQueue pq1("../src/queue1.txt");
	PriorityQueue pq2("../src/queue2.txt");
	PriorityQueue intersct = pq1.intersect(pq2);
	cout << intersct << endl;
}

void testingFileOutput()
{
	cout << "Testing file output: " << endl;
	PriorityQueue pq1("../src/queue1.txt");
	PriorityQueue pq2("../src/queue2.txt");
	ofstream output_file("result.txt");
	output_file << pq1;
	output_file << pq2;
}

void runTest()
{
	testingConsoleInput();
	testingAddingElement();
	testingTopFunction();
	testingPopFunctuin();
	testingSwapFunction();
	testingAddQueueFunction();
	testingIntersectFunction();
	testingFileOutput();
}



