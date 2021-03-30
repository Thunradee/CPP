/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

template <class T>
class LinkedListNode {
public:
	LinkedListNode(T *newPData = nullptr);
	~LinkedListNode();

	// setter and getter
	T *getData(void);
	LinkedListNode<T> *getPNext(void);
	void setData(T *newPData);
	void setPNext(LinkedListNode<T> *newPNext);

private:
	T *pData; // point to Data object located in the heap
	LinkedListNode<T> *pNext; // point to the next node
};

/////////////////////////// Implimentation ///////////////////////////

template <class T>
LinkedListNode<T>::LinkedListNode(T *newPData)
{
	pData = newPData;
	pNext = nullptr;
}

template <class T>
LinkedListNode<T>::~LinkedListNode()
{
	cout << "Inside LinkedListNode Destructor" << endl;
}

template <class T>
T *LinkedListNode<T>::getData(void)
{
	return pData;
}

template <class T>
LinkedListNode<T> *LinkedListNode<T>::getPNext(void)
{
	return pNext;
}

template <class T>
void LinkedListNode<T>::setData(T *newPData)
{
	pData = newPData;
}

template <class T>
void LinkedListNode<T>::setPNext(LinkedListNode<T> *newPNext)
{
	pNext = newPNext;
}