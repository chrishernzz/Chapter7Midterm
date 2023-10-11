//Christian Hernandez
//Date: 10/16/2023
//subscription: CMPR131

#include<iostream>
#include"input (1).h"
#include"TranslationArithmetic.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tCMPR131 Chapter 7: Applications using Stacks by Christian Hernandez(10/16/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Simple Calculator (problem 9, pg 391)";
	cout << "\n\t\t2> Translation of arithmetic expression (problem 10, pg 391)";
	cout << "\n\t\t3> N-Queens Problem (problem 11, pg 391-292)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: going to call my Vector class
//postcondition: going to then call my mainMenu function that will have all the information and the menus as well
void challenge1() {
	//Vector menu;
	//menu.mainMenu();
}
//precondition: going to call my TranslationArithmetic Class
//postcondition: going to then mainMenu function so that will give me the information for the expression
void challenge2() {
	TranslationArithmetic menu;
	menu.menuInformation();
}
//precondition: going to call my ApplicationVectorOrList class
//postcondition: going to then call my mainMenu function that will have all the information and the menus as well
void challenge3() {
	//ApplicationVectorOrList menu;
	//menu.mainMenu();
}
