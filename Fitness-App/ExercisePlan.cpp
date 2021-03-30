/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int n_step_goal, string n_plan_name, string n_date)
{
	step_goal = n_step_goal;
	plan_name = n_plan_name;
	date = n_date;
}

ExercisePlan::ExercisePlan(ExercisePlan &eP)
{
	step_goal = eP.step_goal;
	plan_name = eP.plan_name;
	date = eP.date;
}

ExercisePlan::~ExercisePlan()
{
	cout << "Inside ExercisePlan destructor" << endl;
}

int ExercisePlan::get_step_goal()
{
	return step_goal;
}

string ExercisePlan::get_plan_name()
{
	return plan_name;
}

string ExercisePlan::get_date()
{
	return date;
}

void ExercisePlan::set_step_goal(int n_step_goal)
{
	step_goal = n_step_goal;
}

void ExercisePlan::set_plan_name(string n_plan_name)
{
	plan_name = n_plan_name;
}

void ExercisePlan::set_date(string n_date)
{
	date = n_date;
}

void ExercisePlan::editGoal()
{
	cout << "Enter a new goal steps: ";
	cin >> step_goal;
}

ostream & operator<< (ostream &lhs, ExercisePlan &rhs)
{
	lhs << "Plan name: " << rhs.get_plan_name() << endl;
	lhs << "Goal: " << rhs.get_step_goal() << endl;
	lhs << "Date: " << rhs.get_date() << endl;

	return lhs;
}

fstream & operator<< (fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.get_plan_name() << endl;
	lhs << rhs.get_step_goal() << endl;
	lhs << rhs.get_date() << endl;

	return lhs;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	string n_plan_name, n_step_goal, n_date;
	lhs >> n_plan_name >> n_step_goal >> n_date;
	rhs.set_plan_name(n_plan_name);
	rhs.set_step_goal(stoi(n_step_goal));
	rhs.set_date(n_date);

	return lhs;
}