#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int max, min, num1, num2, num3, num4, num5;
	
	cout << "Please enter 5 integers." << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
			
	do 
	{	
		max = num1;
		if (num2 > max)
			max = num2;
		if (num3 > max)
			max = num3;
		if (num4 > max)
			max = num4;
		if (num5 > max)
			max = num5;
		
		min = num1;
		if (num2 < min)
			min = num2;
		if (num3 < min)
			min = num3;
		if (num4 < min)
			min = num4;
		if (num5 < min)
			min = num5;
		
		if 	(max > 30 || min < 1)
		{
			cout << "Some of your inputs aren't between 1 and 30. Please reenter." << endl;
			cin >> num1 >> num2 >> num3 >> num4 >> num5;
		}
	}
	while (max > 30 || min < 1);
	
	for ( ; num1 > 0; num1--)
	cout << "*";
	cout << endl;
	
	for ( ; num2 > 0; num2--)
	cout << "*";
	cout << endl;
	
	for ( ; num3 > 0; num3--)
	cout << "*";
	cout << endl;	
	
	for ( ; num4 > 0; num4--)
	cout << "*";
	cout << endl;	

	for ( ; num5 > 0; num5--)
	cout << "*";
	cout << endl;

	system ("pause");
	return 0;
}
