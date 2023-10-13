#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//input (1) header files inputs validation
string inputString(string prompt, bool spaces);

class SimpleCalculator{
private:
	//STL stack that will push the expression (parenthesis)
	stack<char>valid;
	//STL stack that will check if its digits or not
	stack<double> digits;
	//STL stack that will check the operators 
	stack<char>operators;
	string expression;
public:
	//defualt constructor
	SimpleCalculator();

	//getters(accesors)
    string getExpression() const;
	//setters(mutators)
	void setExpression(string newString);

	bool checkParenthesis(string expression);
	//double displayCalculation(stack<double>& numbers, stack<char>& operators, istream& ins);
	void evaluateExpression();
	double checkDigitsExpression(string expression);

	//member function to get the menu option
	void menuInformation();
};

