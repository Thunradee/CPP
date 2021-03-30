/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include "Data.h"
#include "List.h"

using namespace std;

class QueueNode
{
public: // Member functions
	QueueNode(int &newCustomerNumber, int &newServiceTime, int &newTotalTime, List *newPList);
	~QueueNode();
	Data *getPData(void);
	int getCustomerNumber(void);
	int getServiceTime(void);
	int getTotalTime(void);
	QueueNode *getPNext(void);
	void setCustomerNumber(int &newCustomerNumber);
	void setServiceTime(int &newServiceTime);
	void setTotalTime(int &newTotalTime);
	void setPNext(QueueNode *newPNext);
	void increaseTotalTime(void);

private:
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!
	List *pList;
	QueueNode *pNext;
};