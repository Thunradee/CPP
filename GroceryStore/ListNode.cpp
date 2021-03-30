/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "ListNode.h"

ListNode::ListNode(string *newItem)
{
	item = newItem;
	pNext = nullptr;
}

ListNode::~ListNode()
{
	cout << "Inside ListNode Destructor" << endl;
}

string ListNode::getItem(void)
{
	return *item;
}

ListNode *ListNode::getPNext(void)
{
	return pNext;
}

void ListNode::setItem(string *newItem)
{
	item = newItem;
}

void ListNode::setPNext(ListNode *newPNext)
{
	pNext = newPNext;
}