//HW5 9.24 TicTacToe Class 
//TicTacToe.cpp

#include <iostream>
#include <cstdlib>

#include "TicTacToe.h"

using namespace std;

//constructor with a member initializer list, and body to initialize array
TicTacToe::TicTacToe()
	:gameStatus(1), player(1), empty(0)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
			board[x][y] = 0;
	}
}

//set function
void TicTacToe::setBoard()
{
	int row, column;
	cout << "Player " << player << ", please enter the coordinate of the destined block on the game board:" << endl;
	cin >> row >> column;
	
	if (board[row - 1][column - 1] != 0)
	{
		cout << "The block has already been filled. Please choose another block." << endl;
		setBoard();
	}
	else if ((1 <= row && row <= 3)&&(1 <= column && column <= 3))
	{	
		board[row - 1][column - 1] = player;
		printBoard();
		checkStatus();
	}
	
	else
	{
		cout << "The coordinate is invalid. Please enter again." << endl;
		setBoard();
	}
}

//other functions
void TicTacToe::printBoard() const
{
	cout << "Current gameboard:" << endl;
	
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			cout << board[x][y] << "|";//separate each block
		}
		cout << board[2][y] << endl;//end line for every three blocks
	}
}

//utility functions to determine the status of the game
void TicTacToe::checkStatus() 
{
	//output current status
	checkEmpty();
	
	if ((checkRow() == player) || (checkColumn() == player) || (checkDiagonal() == player))
		{
			cout << "Player " << player << " won the game!" << endl;
			gameStatus = 0;
		}
		
	else if (empty == 0)
		{	
			cout << "It's a draw game!" << endl;
			gameStatus = 0;
		}
		
	else 
		{
			cout << "It's the next player's turn. Please continue." << endl;
			gameStatus = 1;
		}
		
	//continue the game or not
	if (gameStatus == 0)
		cout << "----------Game over.----------" << endl;
	else
		{
			//alternate to the next player
			if (player == 1)
				player = 2;
			else
				player = 1;
			
			//continue the game	
			setBoard();
		}
}

int TicTacToe::checkEmpty() 
{
	empty=0;
	for (int y = 0; y < 3 ; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[x][y] == 0)
				empty++;
		}
	}
		
	return empty;
}

int TicTacToe::checkRow()
{
	for (int y = 0; y < 3 ; y++)
	{
		if ((board[0][y] == player) && (board[1][y] == player) && (board[2][y]==player))
			return player;
	}
	return 0;
}

int TicTacToe::checkColumn() 
{
	for (int x = 0; x < 3 ; x++)
	{
		if ((board[x][0] == player) && (board[x][1] == player) && (board[x][2] == player))
			return player;
	}
	return 0;
}

int TicTacToe::checkDiagonal() 
{
	if ((board[0][0] == player && board[1][1] == player && board [2][2] == player) 
		|| (board[0][2] == player &&board[1][1] == player && board[2][0] == player))
		return player;
	else
		return 0;
}
