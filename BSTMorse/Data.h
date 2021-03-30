/*************************************************************************************************************
* Programmer: Thunradee Tangsupakij                                                                          *
* Class: CptS 122, Spring, 2019; Lab Section 2                                                               *
* Programming Assignment 6: Morse Code Lookup BST                                                            *
* Date: March 21, 2019                                                                                       *
* Description: This program creates a morse lookup BST, reads messages from a file, converts to morse codes  *
*              and displays to the screen                                                                    *
*************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T, class R>
//template <class R>
class Data {
public:
	Data(T newAlphabet = '\0', R newMorse = "\0");
	Data(Data &copyData);
	//~Data(void);
	T getAlphabet(void);
	R getMorse(void);
	void setAlphabet(T &newAlphabet);
	void setMorse(R &newMorse);

private:
	T alphabet;
	R morse;
};

template <class T, class R>
ostream & operator<<(ostream &lhs, Data<T, R> &data);


///////////// Implimentation /////////////

template <class T, class R>
Data<T, R>::Data(T newAlphabet, R newMorse)
{
	alphabet = newAlphabet;
	morse = newMorse;
}

template <class T, class R>
Data<T, R>::Data(Data &copyData)
{
	alphabet = copyData.alphabet;
	morse = copyData.morse;
}

//Data::~Data(void)
//{
//	cout << "Inside Data Destructor" << endl;
//}

template <class T, class R>
T Data<T, R>::getAlphabet(void)
{
	return alphabet;
}

template <class T, class R>
R Data<T, R>::getMorse(void)
{
	return morse;
}

template <class T, class R>
void Data<T, R>::setAlphabet(T &newAlphabet)
{
	alphabet = newAlphabet;
}

template <class T, class R>
void Data<T, R>::setMorse(R &newMorse)
{
	morse = newMorse;
}

template <class T, class R>
ostream & operator<<(ostream &lhs, Data<T, R> &data)
{
	lhs << data.getAlphabet() << "   " << data.getMorse() << endl;

	return lhs;
}