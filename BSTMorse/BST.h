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
#include <fstream>
#include "BSTNode.h"

using namespace std;

template <class T, class R>
class BST {
public:
	BST();
	~BST();
	BSTNode<T, R> *getRoot(void);
	void insertNode(BSTNode<T, R> *pCur, T &newAlphabet, R &newMorse);
	void printInOrderRecur(BSTNode<T, R> *node);
	bool searchRecur(BSTNode<T, R> *node, T &target, R &morse);

private:
	fstream in;
	BSTNode<T, R> *pRoot;
};

///////////// Implimentation /////////////

template <class T, class R>
BST<T, R>::BST()
{
	in.open("MorseTable.txt"); // open file
	pRoot = nullptr;

	if (in.is_open()) {
		T alphabet;
		R morse;
		string temp;
		while (!in.eof()) {
			in >> alphabet >> morse;
			insertNode(pRoot, alphabet, morse);
		}
		in.close(); // close file
	}
}

template <class T, class R>
BST<T, R>::~BST()
{
	delete pRoot;
}

template <class T, class R>
BSTNode<T, R> *BST<T, R>::getRoot(void)
{
	return pRoot;
}

template <class T, class R>
void BST<T, R>::insertNode(BSTNode<T, R> *pCur, T &newAlphabet, R &newMorse)
{
	if (!pRoot) {
		// empty tree
		pRoot = new BSTNode<T, R>(newAlphabet, newMorse);
	}
	else {
		// not empty tree
		if (newAlphabet < pCur->getAlphabet()) {
			// the new alphaber is less than the alphaber of the current node
			if (pCur->getPLeft()) {
				// check the left node of the current node
				insertNode(pCur->getPLeft(), newAlphabet, newMorse);
			}
			else {
				// insert at the left side of the current node
				pCur->setPLeft(new BSTNode<T, R>(newAlphabet, newMorse));
			}
		}
		else if (newAlphabet > pCur->getAlphabet()) {
			// the new alphaber is greater than the alphaber of the current node
			if (pCur->getPRight()) {
				// check the right node of the current node
				insertNode(pCur->getPRight(), newAlphabet, newMorse);
			}
			else {
				// insert at the right side of the current node
				pCur->setPRight(new BSTNode<T, R>(newAlphabet, newMorse));
			}
		}
		else {
			// duplicated data
			cout << "Duplicated Data" << endl;
		}
	}
}

template <class T, class R>
void BST<T, R>::printInOrderRecur(BSTNode<T, R> *node)
{
	if (node->getPLeft()) {
		printInOrderRecur(node->getPLeft());
	}
	cout << *(node->getData());
	if (node->getPRight()) {
		printInOrderRecur(node->getPRight());
	}
}

template <class T, class R>
bool BST<T, R>::searchRecur(BSTNode<T, R> *node, T &target, R &morse)
{
	if (!node) {
		return false;
	}

	if (target == node->getAlphabet()) {
		// target is found
		morse = node->getMorse();
		return true;
	}

	else if (target < node->getAlphabet()) {
		return searchRecur(node->getPLeft(), target, morse);
	}

	else if (target > node->getAlphabet()) {
		return searchRecur(node->getPRight(), target, morse);
	}
}