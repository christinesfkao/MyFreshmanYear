// 11.11 Polynomial.cpp
#include <iostream>
#include <cstdlib>
#include "Polynomial.h"

using namespace std;

// constructor
Polynomial::Polynomial( int sizeOfArray )
	: size ( sizeOfArray )
{
	polyArray = new int[size];
	
	for ( int i = 0 ; i <= size ; i++ )
		polyArray[i] = 0;
}

// destructor
Polynomial::~Polynomial()
{
	delete [] polyArray;
}

// set function
void Polynomial::setCoefficient( int pow, int coef )
{
	power = pow;
	coefficient = coef;

	polyArray[power] = coefficient;
}

// get function
int Polynomial::getCoefficient( int pow )
{
	power = pow;
	return polyArray[power];
}

void Polynomial::print()
{
	for ( int display = size; display > 0 ; display-- )
		cout << getCoefficient( display ) << "x^" << display << " + ";
	cout << getCoefficient( 0 ) << endl;
}

// algebra
// addition operator+
Polynomial Polynomial::operator+( const Polynomial& operand2 ) 
{
	Polynomial sum ( ( size >= operand2.size ) ? size : operand2.size );
	
	for ( power = 0 ; power < size ; power++ )
		sum.polyArray[power] = polyArray[power] + operand2.polyArray[power];
		
	return sum;
} 

// subtraction operator-
Polynomial Polynomial::operator-( const Polynomial& operand2 ) 
{
	Polynomial diff ( ( size >= operand2.size ) ? size : operand2.size );
	
	for ( power = 0 ; power < size ; power++ )
		diff.polyArray[power] = polyArray[power] - operand2.polyArray[power];
		
	return diff;
} 

// assignment operator=
// override
Polynomial &Polynomial::operator=( const Polynomial& operand2 ) 
{
	if ( operand2.size > size)
	{
		delete [] polyArray;
		int *polyArray = new int [operand2.size];
	}
	
	for ( power = 0 ; power < size ; power++ )
		polyArray[power] = operand2.polyArray[power];
		
	return *this;
} 

// multiplication operator*
Polynomial Polynomial::operator*( const Polynomial& operand2 ) 
{
	Polynomial product ( size + operand2.size );
	
	for ( int power1 = 0 ; power1 < size ; power1++ )
	{
		for ( int power2 = 0 ; power2 < operand2.size ; power2++ )
			product.polyArray[power1 + power2] = polyArray[power1] * operand2.polyArray[power2];
	}

	return product;
} 

// addition assignment operator+=
Polynomial &Polynomial::operator+=( const Polynomial& operand2 )
{
	*this = *this + operand2;
	return *this;
} 

// subtraction assignment operator-=
Polynomial &Polynomial::operator-=( const Polynomial& operand2 )
{
	*this = *this - operand2;
	return *this;
} 

// multiplication assignment operator*=
Polynomial &Polynomial::operator*=( const Polynomial& operand2 )
{
	*this = *this * operand2;
	return *this;
} 


