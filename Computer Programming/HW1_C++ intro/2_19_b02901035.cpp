#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int num1, num2, num3, sum, avg, pro, small, large;
	
	cout << "Input three different integers: ";
	cin >> num1 >> num2 >> num3;
	
	sum = num1 + num2 + num3;
	cout << "Sum is " << sum << endl;
	
	avg = sum / 3;
	cout << "Average is " << avg << endl;
	
	pro = num1 * num2 * num3;
	cout << "Product is " << pro << endl;
	
	
	small = num1;
	if (num2 < small)
		small = num2;
	if (num3 < small)
		small = num3;
	cout << "Smallest is " << small << endl;
	
	large = num1;
	if (num2 > large)
		large = num2;
	if (num3 > large)
		large = num3;
	cout << "Largest is " << large << endl;
	
	system ("pause");
	return 0;
} 
