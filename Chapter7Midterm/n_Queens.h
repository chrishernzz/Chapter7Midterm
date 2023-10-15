#pragma once
#include <stack>
#include "BoardSpaces.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//input (1) header files inputs validation
int inputInteger(string prompt, int startRange, int endRange);

//precondition: going to call (instances) my BoardSpaces class
//postcondition: going to have privates, one stack that checks for the board, three ints, one char, one bool, then in public we got default constructor, setters and getters, and member functions 
class n_Queens : public BoardSpaces{
private:
	//STL that calls the BoardSpaces Class
	stack <BoardSpaces> filledSpaces;
	char shiftDirection;
	int firstColumnPermutaions;
	int filled;
	int boardSize;
	bool gameWon;

public:
	//default constructor
	n_Queens();
	
	//setters(mutators)
	void setBoardSize(int newBoardSize);
	void setFilled(int newFilledAmount);
	//getters(accessors)
	int getBoardSize() const;
	int getFilled() const;
	
	//member function to fill in the board
	void fillBoard();
	//member function to display the board
	void displayBoard(stack<BoardSpaces> filledSpaces) const;

	//member function to get the menu
	void n_QueensMenu();
};