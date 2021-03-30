/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 4: Basic Fitness Application in C++                                                 *
* Date: February 26, 2019                                                                                    *
* Description: This program is a basic fitness application that allows users to download, store and edit     *
*              the diet and exercise plans.                                                                  *
*************************************************************************************************************/

#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	dP_stream.open("dietPlans.txt");
	eP_stream.open("exercisePlans.txt");
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Inside FitnessAppWrapper destructor" << endl;
	if (dP_stream.is_open()) {
		dP_stream.close();
	}
	if (eP_stream.is_open()) {
		eP_stream.close();
	}
}

void FitnessAppWrapper::run_app()
{
	if (dP_stream.is_open() && eP_stream.is_open()) {
		int option = 0;
		while (option != 9) {
			system("cls");
			display_menu();
			option = get_int_input("Enter the option: ", 9, 1);
			if (option == 1) {
				dP_stream.close();
				dP_stream.open("dietPlans.txt");
				load_weekly_plan(dP_stream, dP_list);
			}
			else if (option == 2) {
				eP_stream.close();
				eP_stream.open("exercisePlans.txt");
				load_weekly_plan(eP_stream, eP_list);
			}
			else if (option == 3) {
				dP_stream.close();
				dP_stream.open("dietPlans.txt");
				store_weekly_plan(dP_stream, dP_list);
			}
			else if (option == 4) {
				eP_stream.close();
				eP_stream.open("exercisePlans.txt");
				store_weekly_plan(eP_stream, eP_list);
			}
			else if (option == 5) {
				display_weekly_plan(dP_list);
				system("pause");
			}
			else if (option == 6) {
				display_weekly_plan(eP_list);
				system("pause");
			}
			else if (option == 7) {
				string search_date;
				bool success;
				cout << "Enter the date [mm/dd/yyyy]: ";
				cin >> search_date;
				success = edit_plan(dP_list, search_date);
				if (!success) {
					cout << "The date does not match" << endl;
					system("pause");
				}
			}
			else if (option == 8) {
				string search_date;
				bool success;
				cout << "Enter the date [mm/dd/yyyy]: ";
				cin >> search_date;
				success = edit_plan(eP_list, search_date);
				if (!success) {
					cout << "The date does not match" << endl;
					system("pause");
				}
			}
			else {
				dP_stream.close();
				dP_stream.open("dietPlans.txt");
				store_weekly_plan(dP_stream, dP_list);

				eP_stream.close();
				eP_stream.open("exercisePlans.txt");
				store_weekly_plan(eP_stream, eP_list);
			}
		}
	}
}

void FitnessAppWrapper::display_menu()
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;
}

void FitnessAppWrapper::load_daily_plan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::load_daily_plan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::load_weekly_plan(fstream &fileStream, DPList &list)
{
	if (!list.is_empty()) {
		list.~DPList();
	}
	for (int i = 0; i < 7; ++i) {
		DietPlan *plan = new DietPlan();
		load_daily_plan(fileStream, *plan);
		list.insert_at_end(plan);
	}
}

void FitnessAppWrapper::load_weekly_plan(fstream &fileStream, EPList &list)
{
	if (!list.is_empty()) {
		list.~EPList();
	}
	for (int i = 0; i < 7; ++i) {
		ExercisePlan *plan = new ExercisePlan();
		load_daily_plan(fileStream, *plan);
		list.insert_at_end(plan);
	}
}

void FitnessAppWrapper::display_daily_plan(DietPlan &plan)
{
	cout << plan;
}

void FitnessAppWrapper::display_daily_plan(ExercisePlan &plan)
{
	cout << plan;
}

void FitnessAppWrapper::display_weekly_plan(DPList &list)
{
	//list.print_list(list.get_pHead());
	DPNode *pCur = list.get_pHead();
	cout << "***** DIET WEEKLY PLAN *****" << endl;
	while (pCur) {
		display_daily_plan(*(pCur->get_dP()));
		cout << endl;
		pCur = pCur->get_pNext();
	}
}

void FitnessAppWrapper::display_weekly_plan(EPList &list)
{
	//list.print_list(list.get_pHead());
	EPNode *pCur = list.get_pHead();
	cout << "***** EXERCISE WEEKLY PLAN *****" << endl;
	while (pCur) {
		display_daily_plan(*(pCur->get_eP()));
		cout << endl;
		pCur = pCur->get_pNext();
	}
}

void FitnessAppWrapper::store_daily_plan(fstream &fileStream, DietPlan &plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::store_daily_plan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::store_weekly_plan(fstream &fileStream, DPList &list)
{
	DPNode *pCur = list.get_pHead();
	while (pCur) {
		store_daily_plan(fileStream, *(pCur->get_dP()));
		fileStream << endl;
		pCur = pCur->get_pNext();
	}
}

void FitnessAppWrapper::store_weekly_plan(fstream &fileStream, EPList &list)
{
	EPNode *pCur = list.get_pHead();
	while (pCur) {
		store_daily_plan(fileStream, *(pCur->get_eP()));
		fileStream << endl;
		pCur = pCur->get_pNext();
	}
}

bool FitnessAppWrapper::edit_plan(DPList &list, string &search_date)
{
	bool success = false;
	DPNode *pCur = list.get_pHead();
	while (pCur) {
		if ((pCur->get_dP())->get_date() == search_date) {
			success = true;
			(pCur->get_dP())->editGoal();
			display_daily_plan(*pCur->get_dP());
			system("pause");
			return success;
		}
		pCur = pCur->get_pNext();
	}
	return success;
}

bool FitnessAppWrapper::edit_plan(EPList &list, string &search_date)
{
	bool success = false;
	EPNode *pCur = list.get_pHead();
	while (pCur) {
		if ((pCur->get_eP())->get_date() == search_date) {
			success = true;
			(pCur->get_eP())->editGoal();
			display_daily_plan(*pCur->get_eP());
			system("pause");
			return success;
		}
		pCur = pCur->get_pNext();
	}
	return success;
}

///////////////////// NON MEMBER FUNCTION ///////////////////

int get_int_input(string prompt, int max, int min)
{
	int option = -1;
	while (option < min || option > max) {
		cout << prompt;
		cin >> option;
	}
	return option;
}