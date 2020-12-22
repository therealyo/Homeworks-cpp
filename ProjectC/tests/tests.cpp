#include "tests.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

void testConsole()
{
	printf("Testing console input: \n");
	Customer* que = consoleInput(3);
	printQueue(&que);
	printf("\n");
}

void testPush()
{
	printf("Testing push function: \n");
	char line1[MAXLENGTH];
	char line2[MAXLENGTH];
	fgets(line1, MAXLENGTH, stdin);
	fgets(line2, MAXLENGTH, stdin);
	Customer* cust1 = customer(line1);
	Customer* cust2 = customer(line2);

	push(&cust1, *cust2);
	printQueue(&cust1);
}

void testTop()
{
	printf("Testing top function: \n");
	Customer* que = consoleInput(2);
	Customer* cust = top(&que);
	print(cust);
	printf("\n");
}

void testPop()
{
	printf("Testing pop function: \n");
	Customer* que = consoleInput(2);
	pop(&que);
	printQueue(&que);
	printf("\n");
}

void testReadFromFile()
{
	printf("Testinf file reading: \n");
	char line[] = "../src/queue1.txt";
	Customer* que = readfromfile(line);
	printQueue(&que);
	printf("\n");
}
void testIsEmpty()
{
	printf("Testing console input: \n");
	Customer* que = consoleInput(2);
	if (!isempty(&que))
	{
		printf("Queue isnt empty \n");
	}
	printf("\n");
}

void runTest()
{
	testConsole();
	testPush();
	testTop();
	testPop();
	testReadFromFile();
	testIsEmpty();
}
