//HW4 6.26 Eight Queens
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

//size of the chessboard
const int rows = 8;
const int columns = 8; 

//intialize the value for each square = 0
int chessboard[rows][columns] = {};
int elimination[rows][columns] = {};

//function prototype
int diagonal(int[][columns], int, int);
int eightQueens ();

int main()
{
	srand(time(NULL));

	//check the solution
	while (eightQueens() <= 8)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				chessboard[i][j] = 0;
		} 
		cout << "The solution is not correct. Run the program again." << endl << endl;
	}
	
	cout << "This is a correct solution. End of program." << endl;
			
	system ("pause");
	return 0;
}

int diagonal(int elimination[][columns], int x, int y)
{
	int value = 0;
	
	//upper left corner
	int left = x;
	int up = y;
	for (; left > 0 && up > 0 ; left--, up--)
		value++;
		
	//upper right corner
	int right = 7 - x;
	up = y;
	for (; right > 0 && up > 0; right--, up-- )
		value++;
		
	//lower left corner
	left = x;
	int low = 7 - y;
	for (; left > 0 && low > 0; left--, low--)
		value++;
		
	//lower right corner
	right = 7 - x;
	low = 7 - y;
	for (; right > 0 && low > 0; right--, low--)
		value++;	
		
	return value;
} 

int eightQueens()
{
	cout << "queen" << setw(5) << "x" << setw(5) << "y" << setw(5) << "num" << endl;
	
	//decide how to calculate the eliminated value
	//for each square, at least 15 squares are of the same row or column, including itself
	
	//value = diagonal + 15
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			elimination[i][j] = 15 + diagonal(elimination, i, j) ;
	} 		
	

	//select the next square
	int counter = 1;
	int ansx, ansy;
	
	for (; counter <= 8 ; counter++)
	{
		int min = 29; //one more than the maximum of all the possible value
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (elimination[i][j] < min)
					min = elimination[i][j];
			}
		}
		
		//break the loop when meeting an incorrect solution
		//keep the counter
		if (min == 29)
		{	
			counter--;
			break;	
		}	
		//randomly get the next square from the squares with the smallest elimination number	
		do
		{
			ansx = rand() % 8;
			ansy = rand() % 8;
		}	while (elimination[ansx][ansy] != min);

	
		//to avoid meeting the same square with a queen already, assign 29 to be its elimination number
		elimination[ansx][ansy] = 29;
		chessboard[ansx][ansy] = 1;
		
		//assign 29 to the coordinates that can no longer allow a queen 			
		for (int a = 0; a < 8; a++)
			elimination[a][ansy] = 29;
					
		for (int b = 0; b < 8; b++)
			elimination[ansx][b] = 29;
			
		for (int a = 0; a < 8; a++)
		{
			for (int b = 0; b < 8; b++)
			{	
				if ((a + b == ansx + ansy)||(a - b == ansx - ansy))
					elimination[a][b] = 29;
			}
		}
		
		cout << setw(5) << counter << setw(5) << ansx + 1 << setw(5) << ansy + 1 << setw(5) << min << endl;
	}
	
	//output the chessboard
	
	cout << endl;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chessboard[j][i] == 1)	
				cout << setw(2) << "Q";
			else
				cout << setw(2) << "*";
			
		}
		cout << endl;
	}

	return counter;
}
