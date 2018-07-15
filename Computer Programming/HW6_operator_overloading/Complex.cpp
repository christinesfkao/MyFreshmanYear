// Fig. 11.21: Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

//Constructor
Complex::Complex( double realPart, double imaginaryPart )
	: real( realPart ), imaginary( imaginaryPart )
{
	// empty body
} 

// stream extraction operator<<
ostream& operator<<( ostream& output, const Complex& operand2 )
{
	output << "(" << operand2.real << " , " << operand2.imaginary << ")";
	return output;
} 

// stream insertion operator>>
istream& operator>>( istream& input, Complex& operand2 )
{
	input >> operand2.real >> operand2.imaginary;
	return input;
} 

// addition operator+
Complex Complex::operator+( const Complex& operand2 ) const
{
	return Complex( real + operand2.real, imaginary + operand2.imaginary );
} 

// subtraction operator-
Complex Complex::operator-( const Complex& operand2 ) const
{
	return Complex( real - operand2.real, imaginary - operand2.imaginary);
} 

// multiplication operator*
Complex Complex::operator*( const Complex& operand2 ) const
{
	return Complex( real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real );
}

// equaliity operator==
bool Complex::operator==( const Complex& operand2 ) const
{
	return real == operand2.real && imaginary == operand2.imaginary;
}

// inequality operator!=
bool Complex::operator!=( const Complex& operand2 ) const
{
	return real != operand2.real || imaginary != operand2.imaginary;
}


