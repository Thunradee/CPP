/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "LinkedList.h"
#include "Data.h"

#define IMPORTCOURSE 1
#define LOADMASTERLIST 2
#define STOREMASTERLIST 3
#define MARKABSENCES 4
#define EDITABSENCES 5
#define GENREPORT 6
#define EXIT 7

using namespace std;

class AttendanceTracker {
public:
	AttendanceTracker(string courseList = "classList.csv");
	~AttendanceTracker();

	void runApp();
	
private:
	ifstream input;
	ofstream output;
	LinkedList<Data> students;

	void printMenu();
	void printGenReportMenu();
	void importCourse();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void editAbsences();
	void genReport();
};