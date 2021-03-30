/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include "Queue.h"
#include <cstdlib>
#include <ctime>

#define ITEMLISTSIZE 20
#define EXPRESSLWB 1
#define EXPRESSUPB 5
#define NORMALLWB 3
#define NORMALUPB 8
#define TIMEPRINTALL 10
#define MINPERDAY 1440

class GroceryStore {
public:
	GroceryStore();
	~GroceryStore();
	void run();
	void stimulate(int &stimulateTime);
	int genRandomNum(int lowerBound, int upperBound);
	List *genShoppingList(int &itemNum);
	void displayArrCustomer(string &lane, int &arrTime, int &customerNum);
	void displayFinishedCustomer(string &lane, Data *pData, int &finishedTime);
	void increaseTotalTime(Queue &lane);

private:
	Queue expressLane;
	Queue normalLane;
	string itemList[ITEMLISTSIZE];
	int customerNum;
};