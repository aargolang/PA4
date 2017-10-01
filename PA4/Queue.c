#include "Queue.h"

QueueData *makeQueueNode(QueueData *dat) {
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

	if (pMem != NULL){
		if (pQueue->isEmpty == TRUE) {
			pQueue->pHead = pMem;
			pQueue->pTail = pMem;
			pQueue->isEmpty = FALSE;
		}
		else if (pQueue->isEmpty == FALSE) {
			pQueue->pTail->pNext = pMem;
			pQueue->pTail = pMem;
		}
	}
	return success;
}

QueueData *dequeue(Queue *pQueue) {
	QueueNode *pMem = NULL;
	QueueData *pDat = NULL;
	if (pQueue->isEmpty == TRUE) {
		return NULL;
	}
	else if (pQueue->pHead->pNext == NULL) {
		pDat = pQueue->pHead->qData;
		free(pQueue->pHead);
		pQueue->isEmpty = TRUE;
	}
	else {
		pMem = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		pDat = pMem->qData;
		free(pMem);
	}
	return pDat;
}