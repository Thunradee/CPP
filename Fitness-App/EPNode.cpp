/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "EPNode.h"

EPNode::EPNode(ExercisePlan *n_eP)
{
	eP = n_eP;
	pNext = nullptr;
}

EPNode::~EPNode()
{
	cout << "Inside EPNode destructor" << endl;
}

ExercisePlan* EPNode::get_eP()
{
	return eP;
}

EPNode* EPNode::get_pNext()
{
	return pNext;
}

void EPNode::set_pNext(EPNode *ePN)
{
	pNext = ePN;
}