#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class TranslationArithmetic{
private:
	string expression;
	//STL stack
	stack<char> validExpression;
public:
	//defualt constructor
	TranslationArithmetic();

	//getters(accesors)
	string getExpression() const;
	//setters(mutators)
	void setExpression(string newExpression);
	//member function that check left and right parenthesis
	bool checkParenethesis(string& expression);
	
	//member function to get the menu option
	void menuInformation();

};

