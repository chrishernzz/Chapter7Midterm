#include "SimpleCalculator.h"

//precondition: going to call the ZeroDenominator class
//postcondition: going to put it as a default constructor
SimpleCalculator::DivisionByZero::DivisionByZero() {}
//precondition: going to pass in the SimleCalculator class to give you access to the toString() function
//postcondition: going to then now set the rational which is the ZeroDenominator private = to the toString()
SimpleCalculator::DivisionByZero::DivisionByZero(SimpleCalculator r){
	checking = r.toString();
}
//precondition: going to call the toString() function
//postcondition: going to return the rational (string)
string SimpleCalculator::DivisionByZero::toString(){
	return checking;
}

SimpleCalculator::SimpleCalculator() : expression("") {}

//precondition: going to get the expression 
//postcondition: going to return the private expression
string SimpleCalculator::getExpression() const {
	return expression;
}
//precondition: going to get the new expression
//postcondition: going to set the private expression with the new expression member
void SimpleCalculator::setExpression(string newString) {
	expression = newString;
}
//precondition: going to turn the variables to a string since they are int
//postcondition: going to return a double checking if its 0
string SimpleCalculator::toString(){
	double num2 = 0.0;
	return to_string(num2);
}
//precondition:
//postcondition: 
bool SimpleCalculator::checkParenthesis(string expression) {
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
void SimpleCalculator::evaluateExpression() {
	double num1, num2, total;

	num2 = digits.top();
	digits.pop();
	num1 = digits.top();
	digits.pop();

	switch (operators.top()) {
	case '^': {
		//exponent = num2;
		//taking the power of it 
		total = pow(num1, num2);
	}
			break;
	case '*': {
		total = num1 * num2;
	}
			break;
	case '/': {
		//check if number 2 is not zero, if not zero then divide it
		if (num2 != 0) {
			total = num1 / num2;
		}
		//else if its 0, then error
		else {
			//throw the error
			throw DivisionByZero(*this);
		}
	}
			break;
	case '+': {
		total = num1 + num2;
	}
			break;
	case '-': {
		total = num1 - num2;
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

double SimpleCalculator::checkDigitsExpression(string expression) {
	//getting the size of the string (expression)
	int length = expression.size();
	int i = 0;
	while(i < length) {
		//check if the expression[index] is a digit if digit, then run this
		if (isdigit(expression[i]) || expression[i] == '.') {
			int start = i;
			//loop its less than the expression length and its digit or decimal, loop
			while (i < length && (isdigit(expression[i]) || expression[i] == '.')) {
				i++;
			}
			//going to get the substr of the expression, meaning first argu is where we are starting and the second argu is the
			//length we want to get EX: chris; start = 0, 0-2 we are now getting the first two letters 'ch' 
			string numStr = expression.substr(start, i - start);
			//going to turn the string to a double
			double number = stod(numStr);
			//push the digit (number) to the digit stack
			digits.push(number);
		}
		//else if the expression[index] has any of these operators ^ , + , -, *, or / , run this
		else if (expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') {
			//push the operators to the operator stack
			operators.push(expression[i]);
			i++;
		}
		//ignore the open parenthesis
		else if (expression[i] == '(') {
			i++;
		}
		//else if the expression[index] has the right parenthesis then evluate the digits
		else if (expression[i] == ')') {
			//call the function to evulate the expression
			evaluateExpression();
			i++;
		}
		else {
			i++;
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
//precondition: Na
//postcondition:
void SimpleCalculator::menuInformation() {
	system("cls");
	//SimpleCalculator calc; this is not needed 
	string express;
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;
	try {
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
	//catch the error here and call the what() function to print the error
	}catch (DivisionByZero) {
		//cout << obj.what();
		cout << "\n\t\t\tERROR: Division by zero cannot be done.";
	}
	cout << "\n";
}

