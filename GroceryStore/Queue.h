/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include "QueueNode.h"

using namespace std;

class Queue
{
public: // Member functions
	Queue();
	~Queue();
	QueueNode *getPHead(void);
	QueueNode *getPTail(void);
	void setPHead(QueueNode *pNode);
	void setPTail(QueueNode *pNode);
	bool isEmpty(void);
	void enqueue(int &newCustomerNumber, int &newServiceTime, int &newTotalTime, List *newPList);
	Data *dequeue(void);
	Data *peek(void);
	void printQueueRecursive(QueueNode *pNode);

private:
	QueueNode *pHead;
	QueueNode *pTail;
};