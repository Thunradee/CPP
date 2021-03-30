/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "DietPlan.h"

DietPlan::DietPlan(int new_cal_goal, string new_plan_name, string new_date)
{
	cal_goal = new_cal_goal;
	plan_name = new_plan_name;
	date = new_date;
}

DietPlan::DietPlan(DietPlan &dP)
{
	this->cal_goal = dP.cal_goal;
	this->plan_name = dP.plan_name;
	this->date = dP.date;
}

DietPlan::~DietPlan()
{
	cout << "Inside DietPlan destructor" << endl;
}

int DietPlan::get_cal_goal()
{
	return cal_goal;
}

string DietPlan::get_plan_name()
{
	return plan_name;
}

string DietPlan::get_date()
{
	return date;
}

void DietPlan::set_cal_goal(int new_cal_goal)
{
	cal_goal = new_cal_goal;
}

void DietPlan::set_plan_name(string new_plan_name)
{
	plan_name = new_plan_name;
}

void DietPlan::set_date(string new_date)
{
	date = new_date;
}

void DietPlan::editGoal()
{
	cout << "Enter a new goal calories: ";
	cin >> cal_goal;
}

ostream & operator<< (ostream &lhs, DietPlan &rhs)
{
	lhs << "Plan name: " << rhs.get_plan_name() << endl;
	lhs << "Goal: " << rhs.get_cal_goal() << endl;
	lhs << "Date: " << rhs.get_date() << endl;

	return lhs;
}

fstream & operator<< (fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.get_plan_name() << endl;
	lhs << rhs.get_cal_goal() << endl;
	lhs << rhs.get_date() << endl;

	return lhs;
}

fstream & operator>> (fstream &lhs, DietPlan &rhs)
{
	string new_plan_name, new_cal_goal, new_date;

	lhs >> new_plan_name >> new_cal_goal >> new_date;
	rhs.set_plan_name(new_plan_name);
	rhs.set_cal_goal(stoi(new_cal_goal));
	rhs.set_date(new_date);

	return lhs;
}