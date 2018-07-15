//HW6 b02901035.cpp
#include <iostream>
#include <cstdlib>
#include "Complex.h"
#include "Hugeint.h"
#include "Polynomial.h"
using namespace std;

int main()
{
// 11.8
	double p, q, r, s;
	cin >> p >> q >> r >> s;
	
	Complex x;
	Complex y ( p, q );
	Complex z ( r, s );
	
	cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;
	
	//algebra
	
	x = y + z;
	cout << endl << "x = y + z:" << endl << x << " = " << y << " + " << z << endl;
	
	x = y - z;
	cout << endl << "x = y - z:" << endl << x << " = " << y << " - " << z << endl;
	
	x = y * z;
	cout << endl << "x = y * z:" << endl << x << " = " << y << " * " << z << endl; 
	
	//comparison
	
	if ( y == z )
		cout << endl << "Comparison: y is equal to z." << endl;
		
	if ( y != z )
		cout << endl << "Comparison: y is not equal to z." << endl;

// 11.9	
	// a) Describe precisely how it operates.
	/* 
	It provides two types of constructors 
	to convert long integers and strings (representing large integers) into HugeInt objects.
	
	HugeInt objects are of array types, 
	therefore conversion is done by putting each number in every digit into the array.
	By limiting the size of the array,
	we would be able to take a closer look at each step of the calculations.
	
	It also provides three types of overloaded additional operators, 
	respectively work with HugeInt + int, HugeInt + string, HugeInt + HugeInt, 
	which includes every type of addition that may occur in the program.
	
	For HugeInt + HugeInt, which is the most desired type of addition, 
	carries are considered.
	
	For HugeInt + int and HugeInt + string, 
	the int and string are to be converted into object type HugeInt in order to do further calculations.
	
	The stream extraction operator << is also overloaded to print HugeInt objects.
	Since the object's array is initialized with 0s, 
	we eliminate the leading 0s before printing the objects out to the screen.
	*/
	
	// b) What restrictions does the class have?
	/*
	It cannot calculate "int + string", "int + int", "string + string" types.
	These mentioned situations have to be detected beforehand and converted into HugeInt object types.
	In other words, detection for appropriate type is necessary before any calculation is done.
	
	Besides problems that may occur according to inappropriate datatype, 
	the size of each HugeInt object is also fixed by the time it is constructed.
	If the size of the object grows after certain calculations, 
	errors may occur. 
	The memory allocated for objects should be dynamically assigned 
	in order to maintain the flexibility of its size.

	p.s. "length" is not initialized.
	*/
	
	HugeInt n1( 7654321 );
	HugeInt n2( 7891234 );
	HugeInt n3( "999999999999999999999999999999" );
	HugeInt n4( "1" );
	HugeInt n5;
	
	cout << "n1 is " << n1 << endl
		 << "n2 is " << n2 << endl
		 << "n3 is " << n3 << endl
		 << "n4 is " << n4 << endl
		 << "n5 is " << n5 << endl;
		 
	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << endl << endl;
	cout << n3 << " + " << n4 << endl << " = " << ( n3 + n4 ) << endl << endl;
	
	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << endl << endl;
	
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;
	
//11.11
	// set size
	Polynomial a ( 2 );
	Polynomial b ( 1 );
	Polynomial c ( 2 );
	
	// initialized to be 0
	a.print ();
	b.print ();
	c.print ();
	
	// set value: a = x^2 + 3x + 2	
	a.setCoefficient ( 2 , 1 ); // x^2
	a.setCoefficient ( 1 , 3 ); // 3x
	a.setCoefficient ( 0 , 2 ); // 2
	
	cout << " a = ";
	a.print();
	cout << endl;
	
	// set value: b = 4x + 1
	b.setCoefficient ( 1 , 4 ); // 4x
	b.setCoefficient ( 0 , 1 ); // 1
	
	cout << " b = ";
	b.print();
	cout << endl;	
	
	// addition 
	c = a + b;
	cout << " a + b = " ;
	c.print();
	cout << endl;	

	// subtraction
	c = a - b;
	cout << " a - b = " ;
	c.print();
	cout << endl;
	
	// multiplication
	c = a * b;
	cout << " a * b = " ;
	c.print();
	cout << endl;
	
	// assign a to c
	c = a;
	cout << " c = a = " ;
	c.print();
	cout << endl;
	
	// addition assignment
	c += a;
	cout << " c + a = 2a = " ;
	c.print();
	cout << endl; // c = 2a
	
	// subtraction assignment
	c -= a;
	cout << " 2a - a = a = " ;
	c.print();
	cout << endl; // c = a
	
	// multiplication assignment
	c *= a;
	cout << " a * a = " ;
	c.print();
	cout << endl; // c = a^2
	
	system ("pause");
	return 0;
}
