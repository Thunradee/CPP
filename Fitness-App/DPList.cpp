/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "DPList.h"

DPList::DPList()
{
	pHead = nullptr;
}

DPList::~DPList()
{
	DPNode *pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->get_pNext();
		delete pTemp->get_dP();
		delete pTemp;
	}
}

DPNode* DPList::get_pHead()
{
	return pHead;
}

void DPList::set_pHead(DPNode *n_dP)
{
	pHead = n_dP;
}

bool DPList::is_empty()
{
	return !pHead;
}

bool DPList::insert_at_end(DietPlan *n_dP)
{
	bool success = false;
	DPNode *pMem = new DPNode(n_dP);

	if (pMem) {
		success = true;
		DPNode *pTemp = pHead;
		if (is_empty()) {
			pHead = pMem;
		}
		else {
			while (pTemp->get_pNext()) {
				pTemp = pTemp->get_pNext();
			}
			pTemp->set_pNext(pMem);
		}
	}

	return success;
}

void DPList::print_list(DPNode *pNode)
{
	if (!pNode)
		return;
	cout << *(pNode->get_dP()) << endl;
	print_list(pNode->get_pNext());
}