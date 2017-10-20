#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// queue structure
typedef struct queueData {
	int customerNumber;
	int serviceTime;
	int totalTime;
} QueueData;

typedef struct queueNode {
	QueueData *qData;
	// struct Node *groceryList;
	struct queueNode *pNext;
} QueueNode;

typedef struct queue {
	QueueNode *pHead;
	QueueNode *pTail;
	// BOOL isEmpty;
} Queue;

// generic node dont worry about me yet
typedef struct node {
	char *item;
	struct Node *pNext;
} Node;

QueueData *QDconstructor(int custNum, int servTime, int totTime);
QueueNode *makeQueueNode(QueueData *dat);
Node *makeNode(char *dat);
BOOL enqueue(Queue *pQueue, QueueData *dat);
QueueData *dequeue(Queue *pQueue);
void printQueue(Queue *pQueue, int time);
void freeQueue(Queue *pQueue);
BOOL isEmpty(Queue *pQueue);

#endif