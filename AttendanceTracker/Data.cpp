/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#include "Data.h"

Data::Data(string newNum, string newId, string newName, string newEmail, string newUnit,
	string newProgram, string newLevel, int newAbsenceNum, int newMaxSize)
{
	num = newNum;
	id = newId;
	name = newName;
	email = newEmail;
	unit = newUnit;
	program = newProgram;
	level = newLevel;
	absenceNum = newAbsenceNum;
	absenceDate = new Stack(newMaxSize);
}

Data::~Data()
{
	delete absenceDate;
}

void Data::setNum(string &newNum)
{
	num = newNum;
}

void Data::setId(string &newId)
{
	id = newId;
}

void Data::setName(string &newName)
{
	name = newName;
}

void Data::setEmail(string &newEmail)
{
	email = newEmail;
}

void Data::setUnit(string &newUnit)
{
	unit = newUnit;
}

void Data::setProgram(string &newProgram)
{
	program = newProgram;
}

void Data::setLevel(string &newLevel)
{
	level = newLevel;
}

void Data::setAbsenceNum(int &newAbsenceNum)
{
	absenceNum = newAbsenceNum;
}

void Data::addAbsenceNum(void)
{
	absenceNum += 1;
}

void Data::subAbsenceNum(void)
{
	absenceNum -= 1;
}

bool Data::addAbsenceDate(string &newAbsenceDate)
{
	return absenceDate->push(newAbsenceDate);
}

string Data::getNum(void)
{
	return num;
}

string Data::getId(void)
{
	return id;
}

string Data::getName(void)
{
	return name;
}

string Data::getEmail(void)
{
	return email;
}

string Data::getUnit(void)
{
	return unit;
}

string Data::getProgram(void)
{
	return program;
}

string Data::getLevel(void)
{
	return level;
}

int Data::getAbsenceNum(void)
{
	return absenceNum;
}

Stack *Data::getAbsenceDate(void)
{
	return absenceDate;
}