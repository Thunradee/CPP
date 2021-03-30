/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "Queue.h"

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::~Queue()
{
	QueueNode *pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getPNext();
		delete pTemp;
	}
}

QueueNode *Queue::getPHead(void)
{
	return pHead;
}

QueueNode *Queue::getPTail(void)
{
	return pTail;
}

void Queue::setPHead(QueueNode *pNode)
{
	pHead = pNode;
}

void Queue::setPTail(QueueNode *pNode)
{
	pTail = pNode;
}

bool Queue::isEmpty(void)
{
	return !pHead;
}

void Queue::enqueue(int &newCustomerNumber, int &newServiceTime, int &newTotalTime, List *newPList)
{
	QueueNode *pNode = new QueueNode(newCustomerNumber, newServiceTime, newTotalTime, newPList);

	if (pNode) {
		if (isEmpty()) {
			pHead = pNode;
		}
		else {
			pTail->setPNext(pNode);
		}
		pTail = pNode;
	}
}

/*
PRECONDITION: Queue is not empty
*/
Data *Queue::dequeue(void)
{
	Data *pData = pHead->getPData();
	QueueNode *pTemp = pHead;
	pHead = pHead->getPNext();
	delete pTemp;

	return pData;
}

/*
PRECONDITION: Queue is not empty
*/
Data *Queue::peek(void)
{
	return pHead->getPData();
}

void Queue::printQueueRecursive(QueueNode *pNode)
{
	if (!pNode)
		return;
	cout << *(pNode->getPData()) << endl;
	printQueueRecursive(pNode->getPNext());
}