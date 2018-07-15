//HW5 9.20 Rectangle Class
//Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rec
{
public:
	//default constructor
	Rec(float = 1, float = 1);
	
	//set functions
	void setRec(float, float);
	void setLength(float);
	void setWidth(float);
	
	//get functions
	float getLength();
	float getWidth();
	
	//calculations
	float calPerimeter();
	float calArea();
	
	//display
	void printPerimeter();
	void printArea();
	
private:
	float length;
	float width;
	float perimeter;
	float area;
};

#endif
