//HW4 6.29 The Sieve of Eratosthenes
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int array[1000] = {};//initialize all elements to 0
	
	//initialize all elements to 1 except for 0 and 1
	//ignore 0 and 1, leave them as 0s
	for (int i = 2; i <= 1000; i++)
		array[i] = 1;

	//implement the sieve	
	for (int sieve = 2; sieve < 1000; sieve++)
	{	
		for (int i = 0; i <= 1000 ; i++)
		{
			if ((i > sieve) && (array[i] == 1) && (i % sieve == 0))	
				array[i] = 0;
		}	
	}	
	
	//output the prime numbers
	for (int i = 2; i <= 1000; i++)
	{
		
		if (array[i]==1)
			cout << i << endl;
	}
	
	system("pause");
	return 0;	
}
