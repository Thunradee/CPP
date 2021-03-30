/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include "DietPlan.h"

class DPNode {
public:
	DPNode(DietPlan *n_dP);
	~DPNode();

	DietPlan* get_dP();
	DPNode* get_pNext();
	void set_pNext(DPNode *dPN);

private:
	DietPlan *dP;
	DPNode *pNext;
};