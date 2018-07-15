//HW5.36 Recursive Exponentiation
#include <iostream>
#include <stdlib.h>

using namespace std;

int power(int, int);//function prototype

int main()
{
	int x = 0, y = 0;
	cout << "Calculate the exponential of a number." << endl << "Please enter the base." << endl;
	cin >> x;
	cout << "Please enter the exponent." << endl;
	cin >> y;
	
	cout << "The desired value is " << power ( x , y ) << "." << endl;
	
	system ("pause");
	return 0;	
}

int power(int base, int exponent)
{
	if (exponent == 0) // test for base case
		return 1;
	
	if (exponent == 1) //test for base case
		return base;
			
	else // recursion step
		return base * power (base, exponent-1);	
}
