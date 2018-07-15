#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int rad, diam;
	double circ, area;
	
	cout << "Enter the radius of the circle: ";
	cin >> rad;
	
	diam = rad *2;
	cout << "The diameter is " << diam << endl;
	
	circ = 3.14159 * diam;
	cout << "The circumference is " << circ << endl;
	
	area = 3.14159 * rad * rad;
	cout << "The area is " << area << endl;
	
	system ("pause");
	return 0;
}
