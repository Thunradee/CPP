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
#include "ExercisePlan.h"

class EPNode {
public:
	EPNode(ExercisePlan *n_eP);
	~EPNode();

	ExercisePlan* get_eP();
	EPNode* get_pNext();
	void set_pNext(EPNode *ePN);

private:
	ExercisePlan *eP;
	EPNode *pNext;
};