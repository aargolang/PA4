/********************************
Name:			Arthur Lang
Assignment:		PA4 - Queue: Grocery Store Simulation
Date Started:	9/29/17

Description:	Create a simulation for grocery store lines.

Files:			- main.c
				- Queue.c
				- Queue.h
*********************************/

#include "Queue.h"
#include <ctype.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	Queue normalLane = { NULL,NULL }, expressLane = { NULL,NULL };
	int t = 0, n = 0, nTimer = 0, eTimer = 0, totalCustomers = 0, serviceTime = 0;
	char userInput[50] = { '\0' };
	QueueData *pDat = NULL;
	srand((unsigned int)time(NULL));

	printf("how many minutes would you like to simulate?");
	fgets(userInput, 6, stdin);
	n = atoi(userInput);

	nTimer = (rand() % 6) + 3;
	eTimer = (rand() % 5) + 1;
	while (t < n) {
		//enqueueing 
		if(t == nTimer){
			printf("customer numer %i arrives in the normal line at t = %i \n", totalCustomers, t);
			nTimer = (rand() % 6) + 3 + t;
			serviceTime = (rand() % 6) + 3;
			pDat = QDconstructor(totalCustomers, serviceTime, -t);
			enqueue(&normalLane, pDat);
			totalCustomers++;
		}
		if (t == eTimer){
			printf("customer numer %i arrives in the express line at t = %i \n", totalCustomers, t);
			eTimer = (rand() % 5) + 1 + t;
			serviceTime = (rand() % 5) + 1;
			pDat = QDconstructor(totalCustomers, serviceTime, -t);
			enqueue(&expressLane, pDat);
			totalCustomers++;
		}

		// dequeueing
		if (isEmpty(&normalLane) == FALSE && normalLane.pHead->qData->serviceTime == 0) {
			// dequeue normal lane
			printf("Customer #%i leaves the normal lane ", normalLane.pHead->qData->customerNumber);
			printf("after %i total minutes\n", normalLane.pHead->qData->totalTime + t);
			pDat = dequeue(&normalLane);
			free(pDat);
		}
		if (isEmpty(&expressLane) == FALSE && expressLane.pHead->qData->serviceTime == 0) {
			// dequeue express lane
			printf("Customer #%i leaves the express lane ", expressLane.pHead->qData->customerNumber);
			printf("after %i total minutes\n", expressLane.pHead->qData->totalTime + t);
			pDat = dequeue(&expressLane);
			free(pDat);
		}

		if ((t % 10) == 0 && t != 0) {
			printf("--- Normal Lane ---\n");
			printQueue(&normalLane, t);
			printf("--- Express Lane ---\n");
			printQueue(&expressLane, t);
		}

		// process customers if they exist
		if (isEmpty(&normalLane) == FALSE)
			normalLane.pHead->qData->serviceTime--;
		if (isEmpty(&expressLane) == FALSE)
			expressLane.pHead->qData->serviceTime--;

		t++;

		if ((t % 1440) == 0) {
			freeQueue(&normalLane);
			freeQueue(&expressLane);
			nTimer = (rand() % 6) + 3 + t;
			eTimer = (rand() % 5) + 1 + t;
			totalCustomers = 0;
		}
	}
	freeQueue(&normalLane);
	freeQueue(&expressLane);

	getchar();
	return 0;
}