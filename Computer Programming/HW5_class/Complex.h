//HW5 9.14 Complex Class
//Complex.h

//prevent multiple inclusions of header file
#ifndef COMPLEX_H
#define COMPLEX_H

//class definition
class Complex
{
public:
	Complex(double = 0, double = 0); //default constructor
	
	//set functions
	void setValue(double, double);
		
	//arithmetics
	//using operator overloading can be another approach
	Complex add(Complex, Complex);
	Complex subtract(Complex, Complex);
	
	//display
	void print();	
	
private:
	double realPart;
	double imaginaryPart;	
};


#endif
