#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

string inputString(string prompt, bool spaces);

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
	void evaluateExpression(stack<double>& numbers);
	int getPrecendence(char operation);
};


