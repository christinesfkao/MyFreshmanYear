//HW5 9.14 Complex Class
//Complex.cpp

#include <iostream>
#include <cstdlib>
#include "Complex.h" //include the definition of class Complex

using namespace std;

//constructor with a set function tagged inside
Complex::Complex(double real, double imag)
{
	setValue(real, imag);
}

//set function
void Complex::setValue(double r, double i)
{
	realPart = r;
	imaginaryPart = i;
}

//arithmetics
Complex Complex::add(Complex x, Complex y)
{
	//construct a new object and return it
	//assign the result of this function to a new object in main
	Complex obj;
	
	obj.realPart = x.realPart + y.realPart;
	obj.imaginaryPart = x.imaginaryPart + y.imaginaryPart;
	
	return obj;
}

Complex Complex::subtract(Complex x, Complex y)
{
	//construct a new object and return it
	//assign the result of this function to a new object in main
	Complex obj;
	
	obj.realPart = x.realPart - y.realPart;
	obj.imaginaryPart = x.imaginaryPart - y.imaginaryPart;

	return obj;
}

//display
void Complex::print()
{
	cout << "( " << realPart << " , " << imaginaryPart << " )" << endl;
}
