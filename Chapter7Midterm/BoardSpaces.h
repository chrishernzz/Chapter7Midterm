#pragma once

//precondition: going to create a class that has the board 
//postcondition: going to have two privates that are row and column, default constructor, and setters and getters
class BoardSpaces{
private:
	int row;
	int column;

public:
	//default constructor
	BoardSpaces();
	
	//setters(mutators)
	void setRow(int newRow);
	void setColumn(int newColumn);
	//getters(accesors)
	int getRow() const;
	int getColumn() const;
};