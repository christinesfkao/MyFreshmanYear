//HW5 9.20 Rectangle Class
//Rectangle.cpp

#include <iostream>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;

//constructor
Rec::Rec (float l, float w)
{
	setRec(l, w);
}

//set functions
void Rec::setRec (float l, float w)
{
	setLength(l);
	setWidth(w);
}

void Rec::setLength (float l)
{
	length = (l >= 0.0 && l <= 20.0) ? l : 0.0;
}

void Rec::setWidth (float w)
{
	width = (w >= 0.0 && w <= 20.0) ? w : 0.0;
}

//get functions
float Rec::getLength()
{
	cout << "The length of the rectangle is " << length << "." << endl;
	return length;
}

float Rec::getWidth()
{
	cout << "The width of the rectangle is " << width << "." << endl;
	return width;
}

//calculations
float Rec::calPerimeter()
{
	perimeter = 2 * (length + width);
	return perimeter;
}

float Rec::calArea()
{
	area = length * width;
	return area;
}
//display
void Rec::printPerimeter()
{
	cout << "The perimeter of the rectangle is " << perimeter << "." << endl;
}

void Rec::printArea()
{
	cout << "The area of the rectangle is " << area << "." << endl;
}
