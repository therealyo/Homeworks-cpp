#pragma once

#define MAXLENGTH 100

typedef struct Customer
{
    char* name;
    double time;
    double sum;
    struct Customer* next;
};

Customer* customer(char name[]);
Customer* customer(char* nm, double tm, double sm);
bool compare(Customer cust1, Customer cust2);
bool equal(Customer cust1, Customer cust2);
void print(Customer* cust);


Customer* top(Customer** queue);
Customer* readfromfile(const char filename[]);
Customer* consoleInput(const int size);

void pop(Customer** queue);
void push(Customer** queue, Customer cust);
void printQueue(Customer** queue);
void addQueue(Customer** q1, Customer** q2);

bool isempty(Customer** queue);
