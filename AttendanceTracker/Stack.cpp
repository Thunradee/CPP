/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#include "Stack.h"

Stack::Stack(int newMaxSize)
{
	maxSize = newMaxSize;
	size = 0;
	pTop = new string[newMaxSize];
}

Stack::Stack(Stack &s1)
{
	maxSize = s1.maxSize;
	size = 0;
	pTop = new string[maxSize];
	string date = "";
	for (int i = 0; i < s1.size; ++i) {
		date = s1.pTop[i];
		this->push(date);
	}
}

Stack::~Stack()
{
	delete[] pTop;
}

int Stack::getSize(void)
{
	return size;
}

bool Stack::push(string &newItem)
{
	bool success = false;
	if (size < maxSize) {
		success = true;
		pTop[size] = newItem;
		++size;
	}
	return success;
}

bool Stack::pop(string &item)
{
	bool success = false;
	if (!isEmpty()) {
		success = true;
		size -= 1;
		item = pTop[size];
	}
	return success;
}

bool Stack::peek(string &item)
{
	bool success = false;
	if (!isEmpty()) {
		success = true;
		item = pTop[size - 1];
	}
	return success;
}

bool Stack::isEmpty(void)
{
	return !size;
}