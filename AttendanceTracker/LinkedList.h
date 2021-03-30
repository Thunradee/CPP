/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#pragma once
#include "LinkedListNode.h"

using namespace std;

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	LinkedListNode<T> *getPHead();
	bool isEmpty();
	bool insertAtFront(T *newPData);
	//void printList(void);

private:
	LinkedListNode<T> *pHead;
};

/////////////////////////// Implimentation ///////////////////////////

template <class T>
LinkedList<T>::LinkedList()
{
	pHead = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	LinkedListNode<T> *pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getPNext();
		delete pTemp;
	}
}

template <class T>
LinkedListNode<T> *LinkedList<T>::getPHead()
{
	return pHead;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return !pHead;
}

template <class T>
bool LinkedList<T>::insertAtFront(T *newPData)
{
	bool success = false;
	LinkedListNode<T> *pMem = new LinkedListNode<T>(newPData);

	if (pMem) {
		success = true;
		pMem->setPNext(pHead);
		pHead = pMem;
	}

	return success;
}

//template <class T>
//void LinkedList<T>::printList(void)
//{
//	LinkedListNode<T> *pCur = pHead;
//
//
//	while (pCur) {
//
//		cout << (pCur->getData())
//	}
//}