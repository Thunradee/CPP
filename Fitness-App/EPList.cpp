/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "EPList.h"

EPList::EPList()
{
	pHead = nullptr;
}

EPList::~EPList()
{
	EPNode *pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->get_pNext();
		delete pTemp;
	}
}

EPNode* EPList::get_pHead()
{
	return pHead;
}

void EPList::set_pHead(EPNode *n_eP)
{
	pHead = n_eP;
}

bool EPList::is_empty()
{
	return !pHead;
}

bool EPList::insert_at_end(ExercisePlan *n_eP)
{
	bool success = false;
	EPNode *pMem = new EPNode(n_eP);

	if (pMem) {
		success = true;
		EPNode *pTemp = pHead;
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

void EPList::print_list(EPNode *pNode)
{
	if (!pNode)
		return;
	cout << *(pNode->get_eP()) << endl;
	print_list(pNode->get_pNext());
}