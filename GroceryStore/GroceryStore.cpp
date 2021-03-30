/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "GroceryStore.h"

GroceryStore::GroceryStore()
{
	itemList[0] = "Cereal";
	itemList[1] = "Milk";
	itemList[2] = "Steak";
	itemList[3] = "Egg";
	itemList[4] = "Coke";
	itemList[5] = "Yakult";
	itemList[6] = "Soap";
	itemList[7] = "Bread";
	itemList[8] = "Shampoo";
	itemList[9] = "Chicken";
	itemList[10] = "Butter";
	itemList[11] = "Yogurt";
	itemList[12] = "Water";
	itemList[13] = "Honey";
	itemList[14] = "Toothpaste";
	itemList[15] = "Apple";
	itemList[16] = "Juice";
	itemList[17] = "Coffee";
	itemList[18] = "Toilet Paper";
	itemList[19] = "Bath Bomb";

	customerNum = 0;
}

GroceryStore::~GroceryStore()
{
	cout << "Inside GroceryStore Destructor" << endl;
}

void GroceryStore::run()
{
	int stimulateTime = 0;
	cout << "Enter stimulate time[min]: ";
	cin >> stimulateTime;
	stimulate(stimulateTime);
}

void  GroceryStore::stimulate(int &stimulateTime)
{
	int elapsedTime = 0, normalArrMin = 0, expressArrMin = 0;
	int serviceTime = 0, itemNum = 0, expressArrTime = 0, normalArrTime = 0, totalTime = 0, expressSTR = 0, normalSTR = 0;
	int expressCISNo = 0, normalCISNo = 0;
	string lanes[2] = { "Express Lane", "Normal Lane" };
	Data *pFinCus = nullptr;

	srand((unsigned int)time(NULL));

	// generate arrival time
	expressArrMin = genRandomNum(EXPRESSLWB, EXPRESSUPB);
	normalArrMin = genRandomNum(NORMALLWB, NORMALUPB);
	expressArrTime = elapsedTime + expressArrMin;
	normalArrTime = elapsedTime + normalArrMin;

	while (elapsedTime <= stimulateTime) {
		if (elapsedTime % MINPERDAY == 0) {
			customerNum = 0;
		}
		// a customer arrives to the express lane
		if (expressArrTime == elapsedTime) {
			displayArrCustomer(lanes[0], elapsedTime, ++customerNum); // display arrival customer
			itemNum = genRandomNum(EXPRESSLWB, EXPRESSUPB); // generate the random item number
			serviceTime = itemNum; // one minute per item
								   //totalTime = 0; // total time in the service = 0

			if (expressLane.isEmpty()) {
				// no customer in the lane
				//expressCISNo = customerNum; // the customer is in service
				expressSTR = serviceTime; // remaining time in service = time the customer will be in service
			}

			expressLane.enqueue(customerNum, serviceTime, totalTime, genShoppingList(itemNum)); // put the customer in the lane
			expressArrMin = genRandomNum(EXPRESSLWB, EXPRESSUPB); // generate arrival min for the incomin customer
			expressArrTime = elapsedTime + expressArrMin; // the arrive time
		}
		// a customer arrives to the normal lane
		if (normalArrTime == elapsedTime) {
			displayArrCustomer(lanes[1], elapsedTime, ++customerNum); // display arrival customer
			itemNum = genRandomNum(NORMALLWB, NORMALUPB); // generate the random item number
			serviceTime = itemNum; // one minute per item
								   //totalTime = 0; // total time in the service = 0

			if (normalLane.isEmpty()) {
				// no customer in the lane
				//normalCISNo = customerNum; // the customer is in service
				normalSTR = serviceTime; // remaining time in service = time the customer will be in service
			}

			normalLane.enqueue(customerNum, serviceTime, totalTime, genShoppingList(itemNum)); // put the customer in the lane
			normalArrMin = genRandomNum(NORMALLWB, NORMALUPB); // generate arrival min for the incomin customer
			normalArrTime = elapsedTime + normalArrMin; // the arrive time
		}
		// the customer in the express lane finished checking out
		if (!expressLane.isEmpty() && (expressSTR == 0)) {
			pFinCus = expressLane.dequeue();
			displayFinishedCustomer(lanes[0], pFinCus, elapsedTime);
			if (!expressLane.isEmpty()) {
				expressSTR = expressLane.getPHead()->getServiceTime();
			}
		}
		// the customer in the normal lane finished checking out
		if (!normalLane.isEmpty() && (normalSTR == 0)) {
			pFinCus = normalLane.dequeue();
			displayFinishedCustomer(lanes[1], pFinCus, elapsedTime);
			if (!normalLane.isEmpty()) {
				normalSTR = normalLane.getPHead()->getServiceTime();
			}
		}
		// print both lanes every 10 min
		if ((elapsedTime >= TIMEPRINTALL) && (elapsedTime % TIMEPRINTALL == 0)) {
			cout << "**************************************" << endl;
			cout << "************ EXPRESS LANE ************" << endl;
			if (expressLane.isEmpty()) {
				cout << "Express lane is empty" << endl;
			}
			else {
				expressLane.printQueueRecursive(expressLane.getPHead());
			}
			cout << endl;
			cout << "************ NORMAL LANE *************" << endl;
			if (normalLane.isEmpty()) {
				cout << "Normal lane is empty" << endl;
			}
			else {
				normalLane.printQueueRecursive(normalLane.getPHead());
			}
			cout << "**************************************" << endl;
			cout << "**************************************" << endl;
			cout << endl;
		}

		// update time by 1 minute
		++elapsedTime;
		increaseTotalTime(expressLane);
		increaseTotalTime(normalLane);
		if (expressSTR > 0) {
			--expressSTR;
		}
		if (normalSTR > 0) {
			--normalSTR;
		}
	}
}

/*
Description: Generate a random number between the bounds inclusive
Parameter: int lowerBound A lower bound
		   int upperBound An upper bound
Return: int num A random number
*/
int GroceryStore::genRandomNum(int lowerBound, int upperBound)
{
	int num = 0, dif = upperBound - lowerBound;
	num = rand() % (dif + 1);
	num =+ lowerBound;

	return num;
}

/* 
Description: Generate a shopping list for customers
Parameter: int &itemNum A number of item in the shopping list
Return: List *basket A shopping list
*/
List *GroceryStore::genShoppingList(int &itemNum)
{
	int itemNo = 0;
	List *basket = new List;

	for (int i = 0; i < itemNum; ++i)
	{
		itemNo = genRandomNum(0, ITEMLISTSIZE);
		basket->insertAtFront(itemList + itemNo);
	}

	return basket;
}

void GroceryStore::displayArrCustomer(string &lane, int &arrTime, int &customerNum)
{
	cout << "Min " << arrTime << "\tCustomer No." << customerNum << " arrives to " << lane << endl;
}

void GroceryStore::displayFinishedCustomer(string &lane, Data *pData, int &finishedTime)
{
	cout << "Min " << finishedTime << "\tCustomer No." << pData->getCustomerNumber() << " left the " << lane << "( Total Time: " << pData->getTotalTime() << ")" << endl;
}

void GroceryStore::increaseTotalTime(Queue &lane)
{
	QueueNode *pCur = lane.getPHead();
	while (pCur) {
		pCur->increaseTotalTime();
		pCur = pCur->getPNext();
	}
}