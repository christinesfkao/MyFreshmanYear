//HW5 main function for all
//b02901035.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Complex.h" 
#include "Rectangle.h"
#include "TicTacToe.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

int main()
{
//9.14	
	double real1, imag1, real2, imag2;
	
	//input values for the two objects
	cout << "Input the real part of the first complex number: " << endl;
	cin >> real1;
	
	cout << "Input the imaginary part of the first complex number: " << endl;
	cin >> imag1;
	
	cout << "Input the real part of the second complex number: " << endl;
	cin >> real2;
	
	cout << "Input the imaginary part of the second complex number: " << endl;
	cin >> imag2;
	
	Complex number1(real1, imag1);
	Complex number2(real2, imag2);
	number1.print();
	number2.print();
	
	//addition
	Complex addition;
	addition = addition.add(number1, number2);
	
	cout << "The sum of the two complex numbers is: " << endl;
	
	addition.print();
	
	//subtraction
	Complex subtraction;
	subtraction = subtraction.subtract(number1, number2);
	
	cout << "The difference of the two complex numbers is: " << endl;
	
	subtraction.print();
	
//9.20
	float x, y;
	
	cout << "Please enter the determined length for the rectangle: " << endl;
	cin >> x;
	
	cout << "Please enter the determined width for the rectangle: " << endl;
	cin >> y;
	
	Rec rectangle(x, y);
	
	rectangle.getLength();
	rectangle.getWidth();

	rectangle.calPerimeter();
	rectangle.calArea();

	rectangle.printPerimeter();
	rectangle.printArea();
	
	cout << "End of program." << endl;
	
//9.24
	TicTacToe game;//declare a object
	game.setBoard();

//10.10
	DeckOfCards playCards;
	
	//end of program
	system("pause");
	return 0;
}

