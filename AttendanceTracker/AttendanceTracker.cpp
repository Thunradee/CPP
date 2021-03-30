/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 7: Attendance Tracker w/ class Templates                                            *
* Date: April 6, 2019                                                                                       *
*************************************************************************************************************/

#include "AttendanceTracker.h"

AttendanceTracker::AttendanceTracker(string courseList)
{
	
}

AttendanceTracker::~AttendanceTracker()
{
	if (input.is_open()) {
		input.close();
	}
	if (output.is_open()) {
		output.close();
	}
}

void AttendanceTracker::runApp()
{
	int option = 0;

	while (option != EXIT) {
		system("cls");
		printMenu();
		cout << "Enter a option: ";
		cin >> option;
		system("cls");

		if (option == IMPORTCOURSE) {
			importCourse();
		}
		else if (option == LOADMASTERLIST) {
			loadMasterList();
		}
		else if (option == STOREMASTERLIST) {
			storeMasterList();
		}
		else if (option == MARKABSENCES) {
			markAbsences();
		}
		else if (option == EDITABSENCES) {
			editAbsences();
		}
		else if (option == GENREPORT) {
			genReport();
		}
	}
}

void AttendanceTracker::printMenu()
{
	cout << "MENU:" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl;
}

void AttendanceTracker::printGenReportMenu()
{
	cout << "GENERATE REPORT MENU:" << endl;
	cout << "1. All students" << endl;
	cout << "2. By absence number" << endl;
	cout << "3. Exit to the main menu" << endl;
}

void AttendanceTracker::importCourse()
{
	input.close(); // close the input stream
	input.open("classList.csv", ios::in); // open the students list

	if (input.is_open()) {
		// file is opened successecfully
		char line[100] = "";
		string num = "", id = "", name = "", email = "", unit = "", program = "", level = "";
		
		if (!students.isEmpty()) {
			// the students list is not empty
			students.~LinkedList(); // destroy the exist list
		}
		
		input.getline(line, 100); // read the header of the file

		while (!input.eof()) {
			input.getline(line, 100, ','); // read number
			num = line;
			if (num != "") {
				input.getline(line, 100, ','); // read ID
				id = line;
				input.getline(line, 100, '\"'); // read "
				input.getline(line, 100, '\"'); // read name
				name = line;
				input.getline(line, 100, ','); // read ,
				input.getline(line, 100, ','); // read email
				email = line;
				input.getline(line, 100, ','); // read unit
				unit = line;
				input.getline(line, 100, ','); // read program
				program = line;
				input.getline(line, 100); // read level
				level = line;

				Data *pData = new Data(num, id, name, email, unit, program, level); // create Data object in the heap memory

				if (pData) {
					// Data is located in the heap successfully
					students.insertAtFront(pData); // insert into the list
				}
				else {
					cout << "Failed to locate Data in the heap" << endl;
				}
			}
			
		}
	}
	else {
		cout << "Failed opening the file" << endl;
	}
}

void AttendanceTracker::loadMasterList()
{
	input.close();
	input.open("master.csv", ios::in);

	if (input.is_open()) {
		// file is opened successecfully
		char line[100] = "";
		string num = "", id = "", name = "", first = "", email = "", unit = "", program = "", level = "", absentDate = "";
		int absenceNum = 0;

		if (!students.isEmpty()) {
			// the students list is not empty
			students.~LinkedList(); // destroy the exist list
		}

		input.getline(line, 100); // read the header of the file

		while (!input.eof()) {
			input.getline(line, 100, ','); // read number
			num = line;
			if (num != "") {
				input.getline(line, 100, ','); // read ID
				id = line;
				input.getline(line, 100, ','); // read last name
				name = line;
				input.getline(line, 100, ','); // read name
				first = line;
				name = name + "," + first;
				input.getline(line, 100, ','); // read email
				email = line;
				input.getline(line, 100, ','); // read unit
				unit = line;
				input.getline(line, 100, ','); // read program
				program = line;
				input.getline(line, 100, ','); // read level
				level = line;
				input.getline(line, 100, ','); // read number of absences
				absenceNum = atoi(line);

				Data *pData = new Data(num, id, name, email, unit, program, level, absenceNum); // create Data object in the heap memory

				if (pData) {
					// Data is located in the heap successfully
					if (absenceNum > 0) {
						bool success = false;
						for (int i = 0; i < absenceNum - 1; ++i) {
							input.getline(line, 100, ','); // read a absence date
							absentDate = line;
							success = pData->addAbsenceDate(absentDate);
							if (!success) {
								cout << "failed to add absent date to the list" << endl;
							}
						}
						input.getline(line, 100); // read the last absence date
						absentDate = line;
						success = pData->addAbsenceDate(absentDate);
						if (!success) {
							cout << "failed to add absent date to the list" << endl;
						}
					}
					else {
						input.getline(line, 100);
					}
					students.insertAtFront(pData); // insert into the list
				}
				else {
					cout << "Failed to locate Data in the heap" << endl;
				}
			}
		}
	}
	else {
		cout << "Failed opening the file" << endl;
	}
}

void AttendanceTracker::storeMasterList()
{
	output.close();
	output.open("master.csv", ios::out);
	if (output.is_open()) {
		// file is opened successfully
		output << ", ID, Last name, Firt name, Email, Units, Program, Level, Absence Num" << endl;
		LinkedListNode<Data> *pCur = students.getPHead();
		Data *pTData;
		int absenceNum = 0;
		
		while (pCur) {
			pTData = pCur->getData();
			
			output << pTData->getNum() << ","
				<< pTData->getId() << ","
				<< pTData->getName() << ","
				<< pTData->getEmail() << ","
				<< pTData->getUnit() << ","
				<< pTData->getProgram() << ","
				<< pTData->getLevel() << ","
				<< pTData->getAbsenceNum() << ",";
			absenceNum = pTData->getAbsenceNum();
			if (absenceNum) {
				Stack *pAbsenceDate = pTData->getAbsenceDate();
				Stack *pTStack = new Stack;
				string tDate = "";

				while (!pAbsenceDate->isEmpty()) {
					pAbsenceDate->pop(tDate);
					pTStack->push(tDate);
				}
				Stack opStack(*pTStack);
				
				while (!opStack.isEmpty()) {
					opStack.pop(tDate);
					output << tDate;
					if (!opStack.isEmpty()) {
						output << ",";
					}
				}
				// put the absence dates back to the node
				while (!pTStack->isEmpty()) {
					pTStack->pop(tDate);
					pAbsenceDate->push(tDate);
				}
			}
			output << "\n";
			pCur = pCur->getPNext();
		}
	}
	else {
		cout << "failed to open the file" << endl;
	}
}

void AttendanceTracker::markAbsences()
{
	LinkedListNode<Data> *pCur = students.getPHead();
	string name = "";
	char absence = '\0';

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	string today = to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday);

	while (pCur) {
		name = pCur->getData()->getName();
		cout << "Is " << name << " absent? [y/n]: ";
		cin >> absence;
		if (absence == 'y' || absence == 'Y') {
			// this student is absent
			pCur->getData()->addAbsenceNum();
			pCur->getData()->addAbsenceDate(today);
		}
		pCur = pCur->getPNext();
		system("cls");
	}
}

void AttendanceTracker::editAbsences()
{
	string inputId = "", id = "", abDate = "", popedDate = "";
	bool foundID = false, foundDate = false;
	cout << "Enter the student ID number: ";
	cin >> inputId;
	LinkedListNode<Data> *pCur = students.getPHead();
	Data *pTData;

	while (pCur && (!foundID)) {
		pTData = pCur->getData();
		id = pTData->getId();
		if (inputId == id) {
			foundID = true;
			cout << "Enter the date[yyyy-m-d]: ";
			cin >> abDate;

			Stack *pAbsenceDate = pTData->getAbsenceDate();
			Stack temp(130);
			while (!pAbsenceDate->isEmpty() && (!foundDate)) {
				pAbsenceDate->pop(popedDate);
				if (popedDate == abDate) {
					foundDate = true;
					pTData->subAbsenceNum();
					while (!temp.isEmpty()) {
						temp.pop(popedDate);
						pAbsenceDate->push(popedDate);
					}
				}
				else {
					temp.push(popedDate);
				}
			}
			if (!foundDate) {
				cout << "Could not find the date" << endl;
				system("pause");
				system("cls");
			}
		}
		pCur = pCur->getPNext();
	}
	if (!foundID) {
		cout << "Could not find the student ID number" << endl;
		system("pause");
		system("cls");
	}
}

void AttendanceTracker::genReport()
{
	int option = 0;
	while (option != 3) {
		printGenReportMenu();
		cin >> option;
		system("cls");

		if (option == 1) {
			output.close();
			output.open("allStudentsReport.txt", ios::out);
			if (output.is_open()) {
				int num = 1, absenceNum = 0;
				string date = "";
				LinkedListNode<Data> *pCur = students.getPHead();
				Data *pTData;

				output << "No., ID, Name, Absence Num, Recent absence date" << endl;

				while (pCur) {
					pTData = pCur->getData();
					absenceNum = pTData->getAbsenceNum();
					output << num << ", "
						<< pTData->getId() << ", "
						<< pTData->getName() << ", "
						<< absenceNum;
					if (absenceNum > 0) {
						pTData->getAbsenceDate()->peek(date);
						output << ", " << date;
					}
					output << endl;
					pCur = pCur->getPNext();
					++num;
				}
			}
			else {
				cout << "Failed to open the report file" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (option == 2) {
			int threshold = 0;
			cout << "Enter the absence threshold: ";
			cin >> threshold;
			output.close();
			output.open("reportByAbsence.txt", ios::out);
			if (output.is_open()) {
				LinkedListNode<Data> *pCur = students.getPHead();
				Data *pTData;
				int num = 1, absenceNum = 0;
				output << "No., ID, Name" << endl;

				while (pCur) {
					pTData = pCur->getData();
					absenceNum = pTData->getAbsenceNum();
					
					if (absenceNum > threshold) {
						output << num << ", "
							<< pTData->getId() << ", "
							<< pTData->getName() << endl;
						++num;
					}
					pCur = pCur->getPNext();
				}
			}
			else {
				cout << "Failed to open the report file" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}
