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
	BOOL isEmpty;
} Queue;

// generic node dont worry about me yet
typedef struct node {
	char *item;
	struct Node *pNext;
} Node;

void *makeNode(void *dat, int type);
BOOL enqueue(Queue *pQueue, QueueData *dat);
BOOL dequeue(Queue *pQueue);

//Node *makenode(Record *dat);
//BOOL insertFront(List *pList, Record *dat);
//BOOL store(List *pList);
//BOOL load(List *list);
//BOOL insert(List *pList);
//BOOL del(List *pList);
//BOOL edit(List *list);
//BOOL rate(List *pList);
//BOOL play(List *list);
//BOOL sort(List *pList);
//int nodecmp(Node *n1, Node *n2, int type);
//void shuffle(List *pList);
//int getArtist(List *pList, List *sList, char *artist);
//Record *getRecord(List *sList, char *song);
//Node *getSong(List *pList, char *song);
//void freeList(List *pList);
//BOOL removeNode(List *pList, Node *remNode);
//void resetSubList(List *sList);
//void printList(List *list);
//void printSongs(List *list);
//void printMenu();
//void printEditMenu();
//void clrscr();
//char *getInput(char *in);

#endif