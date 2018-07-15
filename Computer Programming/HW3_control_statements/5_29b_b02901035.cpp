//HW5.29 Prime Numbers 
//(b) check till square root of 10000
#include <iostream>
#include <stdlib.h>
#include <iomanip> //will use function "setw"
#include <cmath> //will use function "sqrt"

using namespace std;
//directly write this code for (b), the function for (a) will be written inside
//The answer to (b) should be square root of 10000, which is 100.

int prime (int);//function prototype

int main ()
{
	int counter = 0;
		
	for (int number = 2; number <= 10000; number++)
	{	
		if (prime (number)==1)
		{	
			cout << setw (8) << number;
			counter++;
			
			//if counter is divisible by 5, start a new line of output
			if (counter % 5 == 0)
				cout << endl;
		}
	}
	cout << endl;
	
	system ("pause");
	return 0;
} 

//the following function "prime" is the solution for 5.29(a)
int prime (int x)//function header
	{
		int decision = 1; //otherwise 2 and 3 won't be able to pass the for loop
		
		for (int a = 2; a <= sqrt (x); a++)//count from 2 to sqrt (x), 0 and 1 can be eliminated
		{	
			decision = 1;
			if (x % a == 0)
			{	
				decision = 0; // means that x is a composite number
				break;
			}
			else 
				decision = 1; // means that x is a prime number
		}
					
		return decision;	
	}
