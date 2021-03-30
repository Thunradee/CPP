/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 6: Morse Code Lookup BST                                                            *
* Date: March 21, 2019                                                                                       *
* Description: This program creates a morse lookup BST, reads messages from a file, converts to morse codes  *
*              and displays to the screen                                                                    *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

template <class T, class R>
class BSTNode {
public:
	BSTNode(T newAlphabet = '\0', R newMorse = "\0");
	BSTNode(BSTNode<T, R> &copyData);
	//~BSTNode();

	Data<T, R> *getData(void);
	T getAlphabet(void);
	R getMorse(void);
	BSTNode<T, R> *getPLeft(void);
	BSTNode<T, R> *getPRight(void);

	void setAlphabet(T &newAlphabet);
	void setMorse(R &newMorse);
	void setPLeft(BSTNode<T, R> *newPLeft);
	void setPRight(BSTNode<T, R> *newPRight);

private:
	Data<T, R> *pData;
	BSTNode<T, R> *pLeft;
	BSTNode<T, R> *pRight;
};

///////////// Implimentation /////////////

template <class T, class R>
BSTNode<T, R>::BSTNode(T newAlphabet, R newMorse)
{
	pData = new Data<T, R>(newAlphabet, newMorse);
	pLeft = nullptr;
	pRight = nullptr;
}

template <class T, class R>
BSTNode<T, R>::BSTNode(BSTNode<T, R> &copyNode)
{
	pData = new Data<T, R>();
	pData->setAlphabet(copyNode.getAlphabet());
	pData->setMorse(copyNode.getMorse());
	pLeft = copyNode.getPLeft();
	pRight = copyNode.getPRight();
}

//template <class T>
//BSTNode<T>::~BSTNode()
//{
//	cout << "Inside BSTNode Destructor" << endl;
//}

template <class T, class R>
Data<T, R> *BSTNode<T, R>::getData(void)
{
	return pData;
}

template <class T, class R>
T BSTNode<T, R>::getAlphabet(void)
{
	return pData->getAlphabet();
}

template <class T, class R>
R BSTNode<T, R>::getMorse(void)
{
	return pData->getMorse();
}

template <class T, class R>
BSTNode<T, R> *BSTNode<T, R>::getPLeft(void)
{
	return pLeft;
}

template <class T, class R>
BSTNode<T, R> *BSTNode<T, R>::getPRight(void)
{
	return pRight;
}

template <class T, class R>
void BSTNode<T, R>::setAlphabet(T &newAlphabet)
{
	pData->setAlphabet(newAlphabet);
}

template <class T, class R>
void BSTNode<T, R>::setMorse(R &newMorse)
{
	pData->setMorse(newMorse);
}

template <class T, class R>
void BSTNode<T, R>::setPLeft(BSTNode<T, R> *newPLeft)
{
	pLeft = newPLeft;
}

template <class T, class R>
void BSTNode<T,R>::setPRight(BSTNode<T, R> *newPRight)
{
	pRight = newPRight;
}