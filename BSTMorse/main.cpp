/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 6: Morse Code Lookup BST                                                            *
* Date: March 21, 2019                                                                                       *
* Description: This program creates a morse lookup BST, reads messages from a file, converts to morse codes  *
*              and displays to the screen                                                                    *
*************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "BST.h"


int main(void) {

	BST<char, string> tree;
	cout << "************** Morse Code Alphabet **************" << endl;
	tree.printInOrderRecur(tree.getRoot());
	fstream in;
	in.open("Convert.txt");
	
	if (in.is_open()) {
		// file is opened successfully
		char temp;
		string line, morse, morseMessage;
		bool isFound = false;

		cout << endl;
		cout << endl;
		cout << "Morse Message::" << endl;
		while (!in.eof()) {
			getline(in, line);
			line += "\n";
			for (int i = 0; i < line.length(); ++i) {
				temp = line[i];
				if (temp == '\n') {
					morseMessage += "\n";
					cout << endl;
				}
				else if (temp == ' ') {
					morseMessage += "  ";
					cout << "  ";
				}
				else {
					if (isalpha(temp)) {
						temp = toupper(temp);
					}
					isFound = tree.searchRecur(tree.getRoot(), temp, morse);
					if (isFound) {
						morseMessage += morse;
						morseMessage += " ";
						cout << morse << " ";
					}
				}
			}
		}
		in.close();

		/*string file = "- .... .. ...   .. ...   .-   - . ... -   --- ..-.   - .... .   -.-. .--. - ...   .---- ..--- ..--- \n-- --- .-. ... .   -.-. --- -.. .   -.-. --- -. ...- . .-. ... .. --- -.   - --- --- .-.. .-.-.- \n";
		cout << file;
		if (file == morseMessage) {
			cout << "correct" << endl;
		}
		else {
			cout << "not correct" << endl;
		}*/
	}

	return 0;
}