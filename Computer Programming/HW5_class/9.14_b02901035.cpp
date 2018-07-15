//HW5 9.14 Complex Class
//9.14_b02901035.cpp

#include <iostream>
#include <cstdlib>
#include "Complex.h" //include the definition of class Complex

using namespace std;

int main()
{
	double real1, imag1, real2, imag2;
	
	//input values for the two objects
	cout << "Input the real part of the first complex number: " << endl;
	cin >> real1;
	
	cout << "Input the imaginary part of the first complex number: " << endl;
	cin >> imag1;
	
	cout << "Input the real part of the second complex number: " << endl;
	cin >> real2;
	
	cout << "Input the imaginary part of the second complex number: " << endl;
	cin >> imag2;
	
	Complex number1(real1, imag1);
	Complex number2(real2, imag2);
	number1.print();
	number2.print();
	
	//addition
	Complex addition;
	addition = addition.add(number1, number2);
	
	cout << "The sum of the two complex numbers is: " << endl;
	
	addition.print();
	
	//subtraction
	Complex subtraction;
	subtraction = subtraction.subtract(number1, number2);
	
	cout << "The difference of the two complex numbers is: " << endl;
	
	subtraction.print();
	
	//end of program
	system("pause");
	return 0;
}
