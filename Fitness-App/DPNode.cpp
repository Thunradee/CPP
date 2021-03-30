/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "DPNode.h"

DPNode::DPNode(DietPlan *n_dP)
{
	dP = n_dP;
	pNext = nullptr;
}

DPNode::~DPNode()
{
	cout << "Inside of DPNode destructor" << endl;
}

DietPlan* DPNode::get_dP()
{
	return dP;
}

DPNode* DPNode::get_pNext()
{
	return pNext;
}

void DPNode::set_pNext(DPNode *dPN)
{
	pNext = dPN;
}