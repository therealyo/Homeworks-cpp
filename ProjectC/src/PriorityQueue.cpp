#include "../headers/PriorityQueue.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>


Customer* customer(char ct[])
{
	Customer* cust = (Customer*)malloc(sizeof(Customer));
	char* next_token = NULL;
	char* token = strtok_s(ct, ", ", &next_token);
	cust->name = token;

	token = strtok_s(NULL, ", ", &next_token);
	char* eptr;
	cust->time = strtod(token, &eptr);

	token = strtok_s(NULL, ", ", &next_token);
	cust->sum = strtod(token, &eptr);

	cust->next = NULL;

	return cust;
}

Customer* customer(char* nm, double tm, double sm)
{
	Customer* cust = (Customer*)malloc(sizeof(Customer));
	cust->name = nm;
	cust->time = tm;
	cust->sum = sm;
	cust->next = NULL;
	return cust;
}

bool compare(Customer cust1, Customer cust2)
{
	if (cust1.time > cust2.time)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool equal(Customer cust1, Customer cust2)
{
	return (cust1.name == cust2.name && cust1.time == cust2.time && cust1.sum == cust2.sum);
}

void print(Customer* cust)
{
	printf("%s, %f, %f \n", cust->name, cust->time, cust->sum);
}


Customer* top(Customer** queue)
{
	return (*queue);
}



void pop(Customer** queue)
{
	if (*queue != NULL)
	{
		Customer* temp = *queue;
		(*queue) = (*queue)->next;
		free(temp);
	}
	else
	{
		printf("Already empty \n");
	}
}

void push(Customer** queue, Customer cust)
{
	Customer* start = (*queue);
	Customer* temp = customer(cust.name, cust.time, cust.sum);

	if ((*queue)->time > cust.time)
	{
		temp->next = *queue;
		(*queue) = temp;
	}
	else
	{
		while (start->next != NULL && start->next->time < cust.time)
		{
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}
}

void printQueue(Customer** queue)
{

	while (!isempty(queue))
	{
		Customer* temp = top(queue);
		print(temp);
		pop(queue);
	}
}

void addQueue(Customer** q1, Customer** q2)
{
	while (!isempty(q2))
	{
		Customer* cust = top(q2);
		pop(q2);
		push(q1, *cust);
	}
}

bool isempty(Customer** queue)
{
	return (*queue) == NULL;
}

Customer* readfromfile(const char filename[])
{
	FILE* input_file;
	errno_t err;
	char nm[MAXLENGTH];

	err = fopen_s(&input_file, filename, "r");

	fgets(nm, MAXLENGTH, input_file);
	Customer* cust = customer(nm);

	while (fgets(nm, MAXLENGTH, input_file) != NULL)
	{
		push(&cust, (*customer(nm)));
	}

	return cust;
}

Customer* consoleInput(const int size)
{
	char line[MAXLENGTH];
	fgets(line, MAXLENGTH, stdin);
	Customer* que = customer(line);

	for (int i = 0; i < size - 1; ++i)
	{
		char line[MAXLENGTH];
		fgets(line, MAXLENGTH, stdin);
		Customer* temp = customer(line);
		push(&que, (*temp));
	}

	return que;
}


