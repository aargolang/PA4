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
	Queue normalLline = { NULL,NULL,TRUE };
	Queue expressLine = { NULL,NULL,TRUE };
	int t = 0, nTimer = 0, eTimer = 0;
	srand(time(NULL));

	QueueData data1 = {1,10,13};
	QueueData data2 = { 2,4,5 };
	QueueData data3 = { 3,2,6 };
	QueueData *pDat = NULL;
	enqueue(&normalLline, &data1);
	enqueue(&normalLline, &data2);
	enqueue(&normalLline, &data3);

	while(normalLline.isEmpty == FALSE){
		pDat = dequeue(&normalLline);
		// free(pDat);
	}

	nTimer = (rand() % 6) + 3;
	eTimer = (rand() % 5) + 1;
	while (t < 500) {
		if(t == eTimer){
			printf("normal line at %i \n", t);
			eTimer = (rand() % 5) + 1 + t;
		}
		if (t == nTimer){
			printf("express line at %i \n", t);
			nTimer = (rand() % 6) + 3 + t;
		}

		t++;
	}




	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n",data1.customerNumber, data1.serviceTime, data1.totalTime);
	// normal.enqueue(&data1);
	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n", data1.customerNumber, data1.serviceTime, data1.totalTime);
	getchar();
	return 0;
}