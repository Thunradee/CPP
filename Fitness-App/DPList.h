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
#include "DPNode.h"

using namespace std;

class DPList {
public:
	DPList();
	~DPList();

	DPNode* get_pHead();
	void set_pHead(DPNode *n_dP);

	bool is_empty();
	bool insert_at_end(DietPlan *n_dP);
	void print_list(DPNode *pNode);

private:
	DPNode *pHead;
};