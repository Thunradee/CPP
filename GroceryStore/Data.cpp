/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 5: Grocery Store Simulation                                                         *
* Date: March 8, 2019                                                                                        *
* Description: This program stimulates two lanes which are express and normal lane in a grocery store        *
*************************************************************************************************************/

#include "Data.h"

Data::Data(int &newCustomerNumber, int &newServiceTime, int &newTotalTime)
{
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = newTotalTime;
}

Data::~Data()
{
	cout << "Inside Data Destructor" << endl;
}

int Data::getCustomerNumber(void)
{
	return customerNumber;
}

int Data::getServiceTime(void)
{
	return  serviceTime;
}

int Data::getTotalTime(void)
{
	return totalTime;
}

void Data::setCustomerNumber(int &newCustomerNumber)
{
	customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int &newServiceTime)
{
	serviceTime = newServiceTime;
}

void Data::setTotalTime(int &newTotalTime)
{
	totalTime = newTotalTime;
}

void Data::increaseTotalTime(void)
{
	++totalTime;
}

//////////////// NON-MEMBER FUNCTION /////////////////

ostream & operator<<(ostream &lhs, Data &rhs)
{
	cout << "Customer Number: " << rhs.getCustomerNumber() << endl;
	cout << "Service Time: " << rhs.getServiceTime() << endl;
	cout << "Total Time: " << rhs.getTotalTime() << endl;

	return lhs;
}