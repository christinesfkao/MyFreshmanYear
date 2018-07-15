//HW5 9.24 TicTacToe Class 
//TicTacToe.h

//prevent multiple inclusions of header file
#ifndef TICTACTOE_H
#define TICTACTOE_H

//class definition
class TicTacToe
{
public:
	//constructor
	TicTacToe();
	
	//set functions
	void setBoard();
		
	void printBoard() const;

private:
	//data members
	int board[3][3];
	int gameStatus;
	int player;
	int empty;
	
	//utility functions to determine the status of the game
	void checkStatus();
	int checkEmpty();
	int checkRow();
	int checkColumn();
	int checkDiagonal();
};

#endif
