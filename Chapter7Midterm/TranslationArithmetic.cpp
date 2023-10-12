#include "TranslationArithmetic.h"

//precondition:
//postcondition: 
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
bool TranslationArithmetic::checkParenethesis(string expression){
	//getting size of the expression;
	int length = expression.size();
	bool failed = false;
	//loop through the string expression
	for (int i = 0; i < length;  i++) {
		//if the expression[index] is equal to the left parenthesis, push it to the stack EX: expression[3] has '(' then its eqaul to left parenthesis
		if (expression[i] == '(') {
			//will push everytime there is a left parenthesis
			validExpression.push(expression[i]);
		}
		//else if the expression[index] is right parenthesis and the stack is not empty, pop it
		else if (expression[i] == ')' && !validExpression.empty()) {
			//if statement that checks if the top is left parenthesis '('
			if (validExpression.top() == '(') {
				//will pop the left parenthesis off the stack since there is a right parenthesis
				validExpression.pop();
			}
			else {
				failed = true;
			}
		}
		//else if there is no '(' in the stack (stack is empty) but there is a ')' then error
		else if (expression[i] == ')' && validExpression.empty()) {
			failed = true;
		}
	}
	//if there is an '(' in the stack then the stack is not empty because there is a left parenthesis that does not match
	if (!validExpression.empty()){
		//flag it to true
		failed = true;
	}

	return failed;
}

//precondition: going to print the information
//postcondition: going to create a menu that accepts 
void TranslationArithmetic::menuInformation(){
	system("cls");
	expression = "a + (b*c^d-e)^(f+g*h)-i)";
	//set the expression
	setExpression(expression);
	//get the expression now
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
