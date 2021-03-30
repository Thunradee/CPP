/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "Test.h"

void testEnqueueEmptyQ(void)
{
	Queue a;
	int customerNum = 1, serviceTime = 5, totalTime = 0;
	// print the starting list (empty list)
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	// enqueue()
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	cout << "Enqueue: customerNum = 1, serviceTime = 5, totalTime = 0" << endl;
	// print the list after enqueued one node
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
}

void testEnqueueOneNodeQ(void)
{
	Queue a;
	int customerNum = 1, serviceTime = 5, totalTime = 0;
	// enqueue 1st node
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	// print the starting list (list with one node)
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	
	customerNum = 2, serviceTime = 10, totalTime = 1;
	// enqueue 2nd node
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	cout << "Enqueue: customerNum = 2, serviceTime = 10, totalTime = 1" << endl;
	// print the list after enqueued the 2nd node
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	
}

void testDequeueOneNodeQ(void)
{
	Queue a;
	Data *pData;
	int customerNum = 1, serviceTime = 5, totalTime = 0;
	// enqueue 1st node
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	// print the strating list (list with one node)
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	// dequeue
	pData = a.dequeue();
	cout << "Dequeue" << endl;
	cout << *pData << endl;
	// print the list after dequeue
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	
}

void testDequeueTwoNodesQ(void)
{
	Queue a;
	Data *pData;
	int customerNum = 1, serviceTime = 5, totalTime = 0;
	// enqueue the 1st node
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	customerNum = 2, serviceTime = 10, totalTime = 1;
	// enqueue the 2nd node
	a.enqueue(customerNum, serviceTime, totalTime, nullptr);
	// print the strating list (list with two nodes
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
	// dequeue
	pData = a.dequeue();
	cout << "Dequeue" << endl;
	cout << *pData << endl;
	// print the list after dequeue
	if (a.isEmpty()) {
		cout << "Queue is empty!" << endl;
	}
	else {
		cout << "***************** Queue *****************" << endl;
		a.printQueueRecursive(a.getPHead());
	}
}

void testRun24HR(void)
{
	GroceryStore a;
	int stimulateTime = 24 * 60;
	a.stimulate(stimulateTime);
}