/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

class Data {
public:
	Data(string newNum = "", string newId = "", string newName = "", string newEmail = "", string newUnit = "", 
		string newProgram = "", string newLevel = "", int newAbsenceNum = 0, int newMaxSize = 130);
	~Data();

	//setter
	void setNum(string &newNum);
	void setId(string &newId);
	void setName(string &newName);
	void setEmail(string &newEmail);
	void setUnit(string &newUnit);
	void setProgram(string &newProgram);
	void setLevel(string &newLevel);
	void setAbsenceNum(int &newAbsenceNum);
	void addAbsenceNum(void);
	void subAbsenceNum(void);
	bool addAbsenceDate(string &newAbsenceDate);

	//getter
	string getNum(void);
	string getId(void);
	string getName(void);
	string getEmail(void);
	string getUnit(void);
	string getProgram(void);
	string getLevel(void);
	int getAbsenceNum(void);
	Stack *getAbsenceDate(void);

private:
	string num;
	string id;
	string name;
	string email;
	string unit;
	string program;
	string level;
	int absenceNum;
	Stack *absenceDate; // point to an array in the heap
};