#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//input (1) header files inputs validation
string inputString(string prompt, bool spaces);

class TranslationArithmetic {
private:
	//STL stack that will push the expression (parenthesis) and will keep track of it
	stack<char> validExpression;
	//stack<char> convert;
	stack<char> trackOperator;
	string expression;
public:
	//defualt constructor
	TranslationArithmetic();

	//getters(accesors)
	string getExpression() const;
	//setters(mutators)
	void setExpression(string newExpression);
	//member function that check left and right parenthesis
	bool checkParenethesis(string expression);
	//member function to convert the infix to a postfix

	string infixToPostfix(string infix);
	//member function to get the menu option
	void menuInformation();

};