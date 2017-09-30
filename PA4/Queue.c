#include "Queue.h"

// pseudo-generic makenode function
void *makeNode(void *dat, int type) {
	void *pMem = NULL;
	if (type == 0) {
		pMem = malloc(sizeof(QueueNode));
		if (pMem != NULL)
			((QueueNode*)pMem)->qData = dat;
	}
	else if (type == 1) {
		pMem = malloc(sizeof(Node));
		if (pMem != NULL)
			((Node*)pMem)->item = dat;
	}
	return pMem;
}


// precondition queue and dat are not null
BOOL enqueue(Queue *pQueue, QueueData *dat) {
	BOOL success = FALSE;
	QueueNode *qMem = (QueueNode*)makeNode(&dat, 0);

	if (qMem != NULL){
		if (pQueue->isEmpty == TRUE) {
			
			// insert first node
		}
		else if (pQueue->isEmpty == FALSE) {
			// insert at back
		}
	}
	return success;
}

BOOL dequeue(Queue *pQueue) {
	BOOL success = FALSE;


	return success;
}