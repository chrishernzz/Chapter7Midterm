#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

//input (1) header files inputs validation
string inputString(string prompt, bool spaces);

//precondition: going to create a class that does a simple calculator
//postcondition: going to have no privates, in public are creating a class called DivisionByZero to try and catch, defualt constructor, member functions 
class SimpleCalculator{
public:
	//Class that checks if its divison by 0 0
	class DivisionByZero {
	private:
		string checking;
	public:
		//defualt constructor
		DivisionByZero();
		//constructor one argument(parameter)
		DivisionByZero(SimpleCalculator r);
		string toString();
	};
	//defualt constructor 
	SimpleCalculator();
	string toString();
	void calculatorMenu();
	void displayCalculation(stack<double>& numbers, istream& ins, double& answer);
	void evaluateExpression(stack<double>& numbers, int& errorCtr);
	int getPrecendence(char operation);
};


