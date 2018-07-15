#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int number, answer = 0, power = 1;
	cout << "Enter a binary integer: ";
	cin >> number;
		
	while (number > 0)
	{
		answer = answer + number % 10 * power;
		power = power * 2;		
		number = number / 10; 
	}
	
	cout << "Its decimal equivalent is " << answer << ". " << endl; 
	
	system ("pause");
	return 0;
} 
