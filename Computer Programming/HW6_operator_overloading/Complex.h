// Fig. 11.20: Complex.h
// Complex class definition
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
	friend ostream &operator<<( ostream &, const Complex & ); // stream extraction
	friend istream &operator>>( istream &, Complex & ); // stream insertion

public:
	Complex( double = 0.0, double = 0.0); // constructor
	
// algebra
	Complex operator+( const Complex & ) const; // addition
	Complex operator-( const Complex & ) const; // subtraction
	Complex operator*( const Complex & ) const; // multiplication
	
// comparison
	bool operator==( const Complex& ) const; // equality
	bool operator!=( const Complex& ) const; // inequality

	
private:
	double real; // real part
	double imaginary; // imaginary part
};  // end class Complex

#endif
