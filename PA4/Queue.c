#include "Queue.h"

QueueNode *makeQueueNode(QueueData *dat) {
	QueueNode *pMem = NULL;
	pMem = malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->qData = dat;
		pMem->pNext = NULL;
	}
	return pMem;
}

Node *makeNode(char *dat) {
	Node *pMem = NULL;
	pMem = malloc(sizeof(Node));
	if (pMem != NULL){
		pMem->item = dat;
		pMem->pNext = NULL;
	}
	return pMem;
}

// precondition queue and dat are not null
BOOL enqueue(Queue *pQueue, QueueData *dat) {
	BOOL success = FALSE;
	QueueNode *pMem = makeQueueNode(dat);

	if (pMem != NULL){							// first node
		if (isEmpty(pQueue) == TRUE) {
			pQueue->pHead = pMem;
			pQueue->pTail = pMem;
			//pQueue->isEmpty = FALSE;
		}										// non-first node
		else {
			pQueue->pTail->pNext = pMem;
			pQueue->pTail = pMem;
		}
	}
	return success;
}

QueueData *dequeue(Queue *pQueue) {
	QueueNode *pMem = NULL;
	QueueData *pDat = NULL;
	if (isEmpty(pQueue) == TRUE) {				// no nodes
		return NULL;
	}
	else if (pQueue->pHead->pNext == NULL) {	// one node
		pDat = pQueue->pHead->qData;
		free(pQueue->pHead);
		pQueue->pHead = NULL;
		pQueue->pTail = NULL;
		//pQueue->isEmpty = TRUE;
	}
	else {										// more than one node
		pMem = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		pDat = pMem->qData;
		free(pMem);
	}
	return pDat;
}

QueueData *QDconstructor(int custNum, int servTime, int totTime) {
	QueueData *dat = malloc(sizeof(QueueData));

	dat->customerNumber = custNum;
	dat->serviceTime = servTime;
	dat->totalTime = totTime;

	return dat;
}

void printQueue(Queue *pQueue, int time) {
	QueueNode *pCur = NULL;

	pCur = pQueue->pHead;
	while (pCur != NULL) {
		printf("->\n");
		printf("customer: \t\t#%i\n", pCur->qData->customerNumber);
		printf("remaining service time:\t%i minutes\n", pCur->qData->serviceTime);
		printf("total time waited: \t%i minutes\n", time + pCur->qData->totalTime);
		pCur = pCur->pNext;
	}
	printf(" - end of line - \n");
}

void freeQueue(Queue *pQueue) {
	QueueData *pDat = NULL;

	while (isEmpty(pQueue) == FALSE) {
		pDat = dequeue(pQueue);
		free(pDat);
	}
}

BOOL isEmpty(Queue *pQueue) {

	if (pQueue->pHead == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}