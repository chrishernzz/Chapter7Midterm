#include "SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(): expression("") {}

//precondition: going to get the expression 
//postcondition: going to return the private expression
string SimpleCalculator::getExpression() const {
	return expression;
}
//precondition: going to get the new expression
//postcondition: going to set the private expression with the new expression member
void SimpleCalculator::setExpression(string newString){
	expression = newString;
}
//precondition:
//postcondition: 
bool SimpleCalculator::checkParenthesis(string expression){
	//getting size of the expression;
	int length = expression.size();
	bool failed = false;
	//loop through the string expression
	for (int i = 0; i < length; i++) {
		//if the expression[index] is equal to the left parenthesis, push it to the stack EX: expression[3] has '(' then its eqaul to left parenthesis
		if (expression[i] == '(') {
			//will push everytime there is a left parenthesis
			valid.push(expression[i]);
		}
		//else if the expression[index] is right parenthesis and the stack is not empty, pop it
		else if (expression[i] == ')' && !valid.empty()) {
			//if statement that checks if the top() of the stack is left parenthesis '('
			if (valid.top() == '(') {
				//will pop the left parenthesis off the stack since there is a right parenthesis
				valid.pop();
			}
		}
		//else if there is no '(' in the stack (stack is empty) but there is a ')' then error
		else if (expression[i] == ')' && valid.empty()) {
			failed = true;
		}
	}
	//if there is an '(' (left parenthesis) left over in the stack (stack is not empty) because there is a left parenthesis that does not match
	if (!valid.empty()) {
		//flag it to true
		failed = true;
	}
	return failed;
}

//precondition:
//postcondition: 
void SimpleCalculator::evaluateExpression(){
	double num1, num2,total;

	num2 = digits.top();
	digits.pop();
	num1 = digits.top();
	digits.pop();

	switch (operators.top()){
	case '+':{
		total = num1 + num2;
	}
			break;
	case '-':{
		total = num1 - num2;
	}
			break;
	case '*':{
		total = num1 * num2;
	}
			break;
	case '/':{
		//check if number 2 is not zero, if not zero then divide it
		if (num2 != 0) {
			total = num1 / num2;
		}
		//else if its 0, then error
		else {
			cout << "\n\t\tERROR: Division by zero cannot be done.";
			total = 0.0;
		}
	}
			break;
	}
	//push the total of it, the digits stack will have the total
	digits.push(total);
	//pop() the total back so it does not read when we go back to the operators
	//digits.pop();
	//pop() the operator so it does not stay, it gets removed once its found
	operators.pop();
}

double SimpleCalculator::checkDigitsExpression(string expression){
	//getting the size of the string (expression)
	int length = expression.size();
	for (int i = 0; i < length;i++) {
		//check if the expression is a digit if digit, then run this
		if (isdigit(expression[i]) || expression[i] == '.') {
			//going to turn the string to a double
			double number = stod(expression.substr(i));
			//push the digit (number) to the digit stack
			digits.push(number);
		}
		//else if the expression has any of these operators ^ , + , -, *, or / , run this
		else if (expression[i] == '^' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			//push the operators to the operator stack
			operators.push(expression[i]);
		}
		//ignore the open parenthesis
		else if (expression[i] == '(') {
		}
		//else if the expression has the right parenthesis then evluate the digits
		else if (expression[i] == ')') {
			//call the function to evulate the expression
			evaluateExpression();
		}
	}
	//while the operators stack is not empty, loop through it and go through the evaluateExpression() function
	while (!operators.empty()) {
		evaluateExpression();
	}
	//if the digits stack is not empty, return whats the top() (this will be the total
	if (!digits.empty()) {
		//retreive the top() of the digits stack (the total)
		return digits.top();
	}
	else {
		cout << "Error: No result found." << endl;
		return 0.0;
	}
}
//precondition:
//postcondition:
void SimpleCalculator::menuInformation() {
	system("cls");
	//SimpleCalculator calc;
	string express;
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	express = inputString("\n\tType a fully parenthesized arithmetic expression: ", true);
	setExpression(express);

	//CHECK FIRST IF PARENTHESIS ARE RIGHT
	if (checkParenthesis(getExpression())) {
		cout << "\n\t\tERROR: Parentheses don't match.";
	}
	else {
		//GET THE TOTAL
		double total = checkDigitsExpression(getExpression());
		cout << "\n\t\tIt evaluates to " << total << ".";
	}
	cout << "\n";
}