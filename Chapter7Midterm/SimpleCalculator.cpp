#include "SimpleCalculator.h"

//precondition: going to call the ZeroDenominator class
//postcondition: going to put it as a default constructor
SimpleCalculator::DivisionByZero::DivisionByZero() {}
//precondition: going to pass in the SimleCalculator class to give you access to the toString() function
//postcondition: going to then now set the rational which is the ZeroDenominator private = to the toString()
SimpleCalculator::DivisionByZero::DivisionByZero(SimpleCalculator r) {
	checking = r.toString();
}
//precondition: going to call the toString() function
//postcondition: going to return the rational (string)
string SimpleCalculator::DivisionByZero::toString() {
	return checking;
}

//Default Constructor
//Precondition: NA
//PostCondition: NA
SimpleCalculator::SimpleCalculator(){}

//precondition: going to turn the variables to a string since they are int
//postcondition: going to return a double checking if its 0
string SimpleCalculator::toString() {
	double num2 = 0.0;
	return to_string(num2);
}
//Precondition: NA
//Postcondition: Displays Calculator Menu
void SimpleCalculator::calculatorMenu(){
	SimpleCalculator calc;
	stack<double> numbers;
	stack<char> operators;
	int number;
	double answer;
	system("cls");
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;
	try {
		cout << "Type a parenthesized or non parenthesized arithmetic expression with postive integers or doubles:\n\n";
		// Clear input buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		displayCalculation(numbers, cin, answer);
	}
	catch (DivisionByZero) {
		cout << "\n\tERROR: Division by zero cannot be done.\n";
	}

}
//Precondition: A stack of doubles, user input with numbers that are positive, a double answer
//Postcondition: Displays expression result
void SimpleCalculator::displayCalculation(stack<double>& numbers, istream& ins, double& answer){
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';
	const char DECIMAL = '.';
	double number;
	char operation;
	char parenthesis;
	stack<char> convert;
	stack<double> storage;
	ofstream outFile;
	int errorCtr = 0;
	int specialError = 0;
	double test;
	outFile.open("Store.txt");

	while (ins && ins.peek() != '\n'){

		if (ins.peek() == LEFT_PARENTHESIS){
			ins >> parenthesis;
			convert.push(parenthesis);
		}
		else if (ins.peek() == ' '){
			ins.ignore();
		}
		else if (isdigit(ins.peek()) || ins.peek() == DECIMAL){
			ins >> number;
			storage.push(number);
			outFile << number << endl;

		}
		else if (ins.peek() == '+' || ins.peek() == '-' || ins.peek() == '*' || ins.peek() == '/' || ins.peek() == '^'){
			ins >> operation;
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && getPrecendence(convert.top()) >= getPrecendence(operation)){
				outFile << convert.top() << endl;
				convert.pop();
			}

			convert.push(operation);

		}
		else if (ins.peek() == RIGHT_PARENTHESIS && !convert.empty()){
			ins.ignore();

			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS){
				operation = convert.top();

				outFile << operation << endl;

				convert.pop();
			}
			if (convert.empty()){
				cout << "ERROR: Unbalanced Parenthesis\n";
				++errorCtr;
			}
			else{
				convert.pop();
			}
		}
		else{
			cout << "ERROR: Incorrect Expression Input\n";
			++errorCtr;
			++specialError;
			while (ins.peek() != '\n'){
				ins.ignore();
			}
			break;
		}
	}
	while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && specialError == 0){
		operation = convert.top();

		outFile << operation << endl;

		convert.pop();
	}
	if (!convert.empty() && specialError == 0){
		cout << "ERROR: Unbalanced Parenthesis\n";
		++errorCtr;
	}
	if (storage.size() <= 1 && specialError == 0){
		cout << "ERROR: Incorrect Expression Input\n";
		++errorCtr;
	}
	if (errorCtr >= 1){
	}
	else{
		evaluateExpression(numbers);
		answer = numbers.top();
		cout << "\nThe Expression Evaluates to: " << answer << endl;
	}
}
//Precondition:A stack of doubles for numbers
//Postcondition: evaluates expression
void SimpleCalculator::evaluateExpression(stack<double>& numbers){
	double num1;
	double num2;
	double answer;
	double storeNum;
	char storeOp;
	ifstream inFile;

	inFile.open("Store.txt");
	while (!inFile.eof()){
		if (isdigit(inFile.peek())){
			inFile >> storeNum;
			numbers.push(storeNum);
		}
		else if (inFile.peek() == '\n'){
			inFile.ignore();
		}
		else if (inFile.peek() == '+' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 + num2);

		}
		else if (inFile.peek() == '-' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 - num2);
		}
		else if (inFile.peek() == '*' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 * num2);
		}
		else if (inFile.peek() == '/' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			if (num2 != 0) {
				numbers.push(num1 / num2);
			}
			//else if its 0, then error
			else {
				//throw the error
				throw DivisionByZero(*this);
			}
			
		}
		else if (inFile.peek() == '^' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(pow(num1, num2));
		}
		else if (numbers.size() < 2 && !inFile.eof()){
			cout << "ERROR: Negative numbers only work outside parentheses.\n\n";
			return;
		}
	}
	inFile.close();
}
//Precondition: a char operator
//Postcondition: returns precendence value;
int SimpleCalculator::getPrecendence(char operation){
	switch (operation){
	case '+': return 1;
		break;
	case '-': return 1;
		break;
	case '*': return 2;
		break;
	case '/': return 2;
		break;
	case '^': return 3;
	}
}