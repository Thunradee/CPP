/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
public:
	Stack(int newMaxSize = 130);
	Stack(Stack &s1);
	~Stack();

	int getSize(void);
	
	bool push(string &newItem);
	bool pop(string &item);
	bool peek(string &item);
	bool isEmpty(void);

private:
	int maxSize; // max size of the array
	int size; // current size of the array
	string *pTop; //pointer point to an array in the heap
};