/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

class ListNode {
public:
	ListNode(string *newItem = nullptr);
	~ListNode();
	string getItem(void);
	ListNode *getPNext(void);
	void setItem(string *newItem);
	void setPNext(ListNode *newPNext);

private:
	string *item;
	ListNode *pNext;
};