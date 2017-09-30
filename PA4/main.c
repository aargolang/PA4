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
	Queue normal = {NULL,NULL,TRUE};
	QueueData data1 = {1,10,13};
	enqueue(&normal, &data1);


	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n",data1.customerNumber, data1.serviceTime, data1.totalTime);
	// normal.enqueue(&data1);
	printf("customer #: %i\nservice Time: %i\ntotal time: %i\n", data1.customerNumber, data1.serviceTime, data1.totalTime);
	getchar();
	return 0;
}