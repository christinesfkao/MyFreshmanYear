// 11.11 Polynomial.h
#ifndef POLY_H
#define POLY_H

class Polynomial
{
public:
	Polynomial( int ); // constructor
	~Polynomial(); // destructor
	
	// set function
	void setCoefficient ( int, int ); // enter power, then enter coefficient 
	
	// get function
	int getCoefficient ( int ); // enter power, return coefficient
	
	void print ();
	
	// algebra
	Polynomial operator+( const Polynomial& ); // addition
	Polynomial operator-( const Polynomial& ); // subtraction
	Polynomial &operator=( const Polynomial& ); // assignment
	Polynomial operator*( const Polynomial& ); // multiplication
	Polynomial &operator+=( const Polynomial& ); // addition assignment
	Polynomial &operator-=( const Polynomial& ); // subtraction assignment
	Polynomial &operator*=( const Polynomial& ); // multiplication assignment 
	
private:
	int size;
	int power;
	int coefficient;
	int *polyArray;
};

#endif