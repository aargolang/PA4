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
#include <stdio.h>
#include <Windows.h>

int main()
{
	Queue normalLline = { NULL,NULL,TRUE };
	Queue expressLine = { NULL,NULL,TRUE };
	int time = 0;

	QueueData data1 = {1,10,13};
	QueueData data2 = { 2,4,5 };
	QueueData data3 = { 3,2,6 };
	QueueData *pDat = NULL;
	enqueue(&normalLline, &data1);
	enqueue(&normalLline, &data2);
	enqueue(&normalLline, &data3);

	while(normalLline.isEmpty==FALSE){
		pDat = dequeue(&normalLline);
	}

	while (time < 1440) {

		time++;
	}




	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n",data1.customerNumber, data1.serviceTime, data1.totalTime);
	// normal.enqueue(&data1);
	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n", data1.customerNumber, data1.serviceTime, data1.totalTime);
	getchar();
	return 0;
}