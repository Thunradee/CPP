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
#include "EPNode.h"

class EPList {
public:
	EPList();
	~EPList();

	EPNode* get_pHead();
	void set_pHead(EPNode *n_eP);

	bool is_empty();
	bool insert_at_end(ExercisePlan *n_eP);
	void print_list(EPNode *pNode);

private:
	EPNode *pHead;
};