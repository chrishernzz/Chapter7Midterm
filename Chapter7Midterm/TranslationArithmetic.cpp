#include "TranslationArithmetic.h"


TranslationArithmetic::TranslationArithmetic() :expression("") {}

//precondition: going to get the expression 
//postcondition: going to return the private expression
string TranslationArithmetic::getExpression() const{
	return expression;
}
//precondition: going to get the new expression
//postcondition: going to set the private expression with the new expression member
void TranslationArithmetic::setExpression(string newExpression){
	expression = newExpression;
}

//precondition: going to pass in a string expression as our parameter
//postcondition: going to return value indicates that the parenthesis in the given expression are balanced, if not then return value is false
bool TranslationArithmetic::checkParenethesis(string& expression){
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	//getting size of the expression;
	int length = expression.size();
	bool failed = false;
	
	//checking if there is left parenthesis beginning of the expression, flag it to true right away
	if (expression[0] != LEFT_PARENTHESIS) {
		//flag it to true
		failed = true;
	}
	for (int i = 0; !failed && (i < length); i++) {
		//if the expression[index] is equal to the left parenthesis, push it to the stack EX: expression[3] has '(' then its eqaul to left parenthesis
		if (expression[i] == LEFT_PARENTHESIS) {
			//will push everytime there is a left parenthesis
			validExpression.push(expression[i]);
		}
		//else if there is right parenthesis and the stakc is not empty, pop it
		else if (expression[i] == RIGHT_PARENTHESIS && !validExpression.empty()) {
			//will pop the left parenthesis off the stack since there is a right parenthesis
			validExpression.pop();
		}
		//else if there is no '(' in the stack (stack is empty) but there is a ')' then error
		else if (expression[i] == RIGHT_PARENTHESIS && validExpression.empty()) {
			failed = true;
		}
	}
	//if there is an '(' in the stack and is not empty then error because there is a parenthesis that does not match
	if (!validExpression.empty()){
		failed = true;
	}

	return failed;
}

//precondition: going to print the information
//postcondition: going to create a menu that accepts 
void TranslationArithmetic::menuInformation(){
	system("cls");
	char option;
	string expression = "(5 + 9 + b*c(^d-e)^(f+g*h)-i";
	setExpression(expression);
	expression = getExpression();
	cout << "\n\t2> Translation of Arithmetic Expression";
	cout << "\n\t" << string(82, char(205)) << "\n";

	//if true
	if (checkParenethesis(expression)) {
		cout << "\n\t\tInfix expression: " << expression;
		cout << "\n\t\tPostfix expression: ERROR: inbalanced parentheses.";
	}
	else {
		cout << "\n\t\tInfix expression: " << expression;
		cout << "\n\t\tPostfix expression: VALID: balanced parenthesis!";
	}

	cout << "\n\n";
}
