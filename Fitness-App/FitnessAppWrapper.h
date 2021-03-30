/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DPList.h"
#include "EPList.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();
	~FitnessAppWrapper();

	/*DPList get_dPList();
	EPList get_ePList();
	fstream get_dP_stream();
	fstream get_eP_stream();*/
	
	void run_app();
	void display_menu();
	void load_daily_plan(fstream &fileStream, DietPlan &plan);
	void load_daily_plan(fstream &fileStream, ExercisePlan &plan);
	void load_weekly_plan(fstream &fileStream, DPList &list);
	void load_weekly_plan(fstream &fileStream, EPList &list);
	void display_daily_plan(DietPlan &plan);
	void display_daily_plan(ExercisePlan &plan);
	void display_weekly_plan(DPList &list);
	void display_weekly_plan(EPList &list);
	void store_daily_plan(fstream &fileStream, DietPlan &plan);
	void store_daily_plan(fstream &fileStream, ExercisePlan &plan);
	void store_weekly_plan(fstream &fileStream, DPList &list);
	void store_weekly_plan(fstream &fileStream, EPList &list);
	bool edit_plan(DPList &list, string &search_date);
	bool edit_plan(EPList &list, string &search_date);

private:
	DPList dP_list;
	EPList eP_list;
	fstream dP_stream;
	fstream eP_stream;
};

int get_int_input(string prompt, int max, int min);