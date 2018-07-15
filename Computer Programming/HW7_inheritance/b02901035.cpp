// HW7 12.7 Richer Shape Hierarchy

/*
two-dimensional shapes:
	circle
	square
	rectangle
	pentagon
	heptagon
	hexagon
	octagon
	nonagon
	dectagon
	trapezoid
	trapezium
	parallelogram
	rhombus
	kite
	star
	moon
	crescent
	cross
	heart
	oval
	ellipse
	arrow
	pie
	spade
	club
	curvilinear triangle
	quatrefoil
	
three-dimensional shapes:
	sphere
	hemisphere
	cylinder
	cone
	cube
	cuboid
	prism
	tetrahedron
	octahedron
	dodecahedron
	frustum
	wedge
	torus
	
	pyramid
*/

// HW7 12.10 Account Inheritance Hierarchy
// main function.
// 12.10_b02901035.cpp

#include <iostream>
#include <cstdlib>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
	Account x( -50.0 );	
	cout << x.getBalance();
	
	Account y( 50.0 );
	cout << y.getBalance();
	y.credit( 25.0 );
	cout << y.getBalance();
	y.debit( 30.0 );
	cout << y.getBalance();
	y.debit( 40.0 );
	cout << y.getBalance();
	
	
	
	system ("pause");
	return 0;
}
