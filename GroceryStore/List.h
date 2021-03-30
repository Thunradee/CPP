/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "ListNode.h"

using namespace std;

class List {
public:
	List();
	~List();
	ListNode *getPHead(void);
	void setPHead(ListNode *pNode);
	bool isEmpty(void);
	void insertAtFront(string *newItem);
	string deleteAtFront(void);
	void printListRecursive(ListNode *pNode);

private:
	ListNode *pHead;
};