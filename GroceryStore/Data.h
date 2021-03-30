/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

class Data
{
public: // Member functions
	Data(int &newCustomerNumber, int &newServiceTime, int &newTotalTime);
	~Data();
	int getCustomerNumber(void);
	int getServiceTime(void);
	int getTotalTime(void);
	void setCustomerNumber(int &newCustomerNumber);
	void setServiceTime(int &newServiceTime);
	void setTotalTime(int &newTotalTime);
	void increaseTotalTime(void);

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; 

ostream & operator<<(ostream &lhs, Data &rhs);