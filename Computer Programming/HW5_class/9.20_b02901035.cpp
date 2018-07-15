//HW5 9.20 Rectangle Class
//9.20_b02901035.cpp

#include <iostream>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;

int main()
{
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
	
	system("pause");
	return 0;
}

