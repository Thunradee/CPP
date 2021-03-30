/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "List.h"

List::List()
{
	pHead = nullptr;
}

List::~List()
{
	ListNode *pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getPNext();
		delete pTemp;
	}
}

ListNode *List::getPHead(void)
{
	return pHead;
}

void List::setPHead(ListNode *pNode)
{
	pHead = pNode;
}

bool List::isEmpty(void)
{
	return !pHead;
}

void List::insertAtFront(string *newItem)
{
	ListNode *pNode = new ListNode(newItem);
	if (pNode) {
		pNode->setPNext(pHead);
		pHead = pNode;
	}
}

string List::deleteAtFront(void)
{
	ListNode *pTemp = pHead;
	string item = pTemp->getItem();
	pHead = pHead->getPNext();
	delete pTemp;

	return item;
}

void List::printListRecursive(ListNode *pNode)
{
	if (pNode)
		return;
	cout << "Item: " << pNode->getItem() << endl;
	printListRecursive(pNode->getPNext());
}