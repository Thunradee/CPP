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

using namespace std;

class ExercisePlan {
public:
	ExercisePlan(int n_step_goal = 0, string n_plan_name = "", string n_date = "");
	ExercisePlan(ExercisePlan &eP);
	~ExercisePlan();

	int get_step_goal();
	string get_plan_name();
	string get_date();

	void set_step_goal(int n_step_goal);
	void set_plan_name(string n_plan_name);
	void set_date(string n_date);

	void editGoal();

private:
	int step_goal;
	string plan_name;
	string date;
};

ostream & operator<< (ostream &lhs, ExercisePlan &rhs);
fstream & operator<< (fstream &lhs, ExercisePlan &rhs);
fstream & operator>> (fstream &lhs, ExercisePlan &rhs);