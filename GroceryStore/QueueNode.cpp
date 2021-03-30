/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "QueueNode.h"

QueueNode::QueueNode(int &newCustomerNumber, int &newServiceTime, int &newTotalTime, List *newPList)
{
	pData = new Data(newCustomerNumber, newServiceTime, newTotalTime);
	pList = newPList;
	pNext = nullptr;
}

QueueNode::~QueueNode()
{
	cout << "Inside QueueNode Destructor" << endl;
}

Data *QueueNode::getPData(void)
{
	return pData;
}

int QueueNode::getCustomerNumber(void)
{
	return pData->getCustomerNumber();
}

int QueueNode::getServiceTime(void)
{
	return pData->getServiceTime();
}

int QueueNode::getTotalTime(void)
{
	return pData->getTotalTime();
}

QueueNode *QueueNode::getPNext(void)
{
	return pNext;
}

void QueueNode::setCustomerNumber(int &newCustomerNumber)
{
	pData->setCustomerNumber(newCustomerNumber);
}

void QueueNode::setServiceTime(int &newServiceTime)
{
	pData->setServiceTime(newServiceTime);
}

void QueueNode::setTotalTime(int &newTotalTime)
{
	pData->setTotalTime(newTotalTime);
}

void QueueNode::setPNext(QueueNode *newPNext)
{
	pNext = newPNext;
}

void QueueNode::increaseTotalTime(void)
{
	pData->increaseTotalTime();
}