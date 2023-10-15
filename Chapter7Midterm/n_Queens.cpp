#include "n_Queens.h"

//precondition:
//postcondition:
bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace);

//precondition:
//postcondition:
n_Queens::n_Queens(){
	shiftDirection = 'R';
	firstColumnPermutaions = 0;
	boardSize = 0;
	filled = 0;
	gameWon = false;
}
//precondition:
//postcondition:
void n_Queens::setBoardSize(int newBoardSize){
	boardSize = newBoardSize;
}
//precondition:
//postcondition:
void n_Queens::setFilled(int newFilledAmount){
	filled = newFilledAmount;
}
//precondition:
//postcondition:
int n_Queens::getBoardSize() const{
	return boardSize;
}
//precondition:
//postcondition:
int n_Queens::getFilled() const{
	return filled;
}
//precondition:
//postcondition:
void n_Queens::fillBoard(){
	BoardSpaces currentSpace;
	bool queenConflict = false;
	boardSize = inputInteger("\n\tEnter a number(1..100) of queens: ", 1, 100);
	currentSpace.setColumn(inputInteger("\tEnter the column to place the first queen : ", 1, boardSize));
	filledSpaces.push(currentSpace);
	firstColumnPermutaions++;
	do{
		queenConflict = checkIfConflict(boardSize, filledSpaces, currentSpace);
		if (queenConflict == false){
			filled++;
			if (filled == boardSize){
				gameWon = true;
				displayBoard(filledSpaces);
				break;
			}
			else{
				currentSpace.setRow(currentSpace.getRow() + 1);
				currentSpace.setColumn(1);
				filledSpaces.push(currentSpace);
			}
		}
		else if (currentSpace.getColumn() < boardSize){
			currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
			filledSpaces.top() = currentSpace;

		}
		else if (currentSpace.getColumn() >= boardSize){
			while (filledSpaces.size() > 1){
				if (filledSpaces.top().getColumn() < boardSize){
					currentSpace.setRow(filledSpaces.top().getRow());
					currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
					filledSpaces.top() = currentSpace;
					break;
				}
				filledSpaces.pop();
				filled--;
			}
			if (filledSpaces.top().getRow() == 1){
				if (firstColumnPermutaions == boardSize){
					cout << "\n\tNo Solution Found. " << endl;
					return;
				}
				else if (filledSpaces.top().getColumn() == boardSize){
					filledSpaces.top().setColumn(boardSize - firstColumnPermutaions);
					currentSpace.setRow(1);
					currentSpace.setColumn(filledSpaces.top().getColumn());
					shiftDirection = 'L';
				}
				else{
					currentSpace.setRow(1);
					if (shiftDirection == 'L')
					{
						currentSpace.setColumn(filledSpaces.top().getColumn() - 1);
					}
					currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
					filledSpaces.top() = currentSpace;
					firstColumnPermutaions++;
				}

			}
		}
	} while (gameWon == false);
}
//precondition:
//postcondition:
void n_Queens::displayBoard(stack<BoardSpaces> filledSpaces) const{
	cout << endl << "\t" << boardSize << "-Queens Soulution." << endl;
	cout << "\n\t" << std::string(1, char(201));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(187)) << endl;
	for (int index = 0; index < boardSize; index++){
		cout << "\t" << string(1, char(186)) << " ";
		for (int j = 0; j < boardSize; j++){
			if (filledSpaces.top().getColumn() == (j + 1)){
				cout << 'Q';
			}
			else{
				cout << '-';
			}
			if (j < boardSize - 1){
				cout << string(1, char(179));
			}
		}
		cout << " " << string(1, char(186)) << endl;
		filledSpaces.pop();
	}
	cout << "\t" << std::string(1, char(200));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(188)) << endl;
}
//precondition:
//postcondition:
bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace){
	int stackSize = filledSpaces.size();

	if (filledSpaces.size() > 1){
		filledSpaces.pop();
		if (abs(filledSpaces.top().getColumn() - currentSpace.getColumn()) <= 1){
			return true;
		}
		else{
			while (!filledSpaces.empty()){
				if (filledSpaces.top().getColumn() == currentSpace.getColumn()){
					return true;
				}
				filledSpaces.pop();
			}
		}
	}

	return false;
}
//precondition:
//postcondition:
void n_Queens::n_QueensMenu(){
	system("cls");
	cout << "\n\t3> n_Queens Problem";
	cout << "\n\t" << string(82, char(205)) << "\n";
	fillBoard();
}