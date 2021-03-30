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
#include <string>
#include <fstream>

using namespace std;

class DietPlan {
public:
	DietPlan(int new_cal_goal = 0, string new_plan_name = "", string new_date = "");
	DietPlan(DietPlan &dP);
	~DietPlan();

	int get_cal_goal();
	string get_plan_name();
	string get_date();

	void set_cal_goal(int new_cal_goal);
	void set_plan_name(string new_plan_name);
	void set_date(string new_date);

	void editGoal();

private:
	int cal_goal;
	string plan_name;
	string date;
};

ostream & operator<< (ostream &lhs, DietPlan &rhs);
fstream & operator<< (fstream &lhs, DietPlan &rhs);
fstream & operator>> (fstream &lhs, DietPlan &rhs);