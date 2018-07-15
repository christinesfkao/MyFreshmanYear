//HW5.29 Prime numbers 
//(c) check till 10000/2 instead of square root of 10000

#include <iostream>
#include <stdlib.h>
#include <iomanip> //will use function "setw"
#include <cmath> //will use function "sqrt"

using namespace std;
//though (b) and (c) will get the same solution, (c) will calculate even more times than (b)
//because sqrt(x) is usually smaller than x/2 (according to Jensen's Inequality
//and sqrt(x) is the least number of times to check if a number is anothers' factor 
//therefore, solution (b) is more efficient

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

int prime (int x)//function header
	{
		int decision = 1;
		
		for (int a = 2; a <= (x/2); a++)//count from 2 to x/2, 0 and 1 can be eliminated
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

