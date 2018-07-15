//5.37 Fibonacci Series
//(a) nonrecursive, datatype: int
//The largest int Fibonacci number that can be printed is when n=46, fibonacci(46)=1836311903 

#include <iostream>
#include <stdlib.h>

using namespace std;

int fibonacci(int);

int main()
{
	int x = 0;
	
	cout << "Please enter the desired n th number in the Fibonacci series:" << endl 
		 << "(Starting from the 0th)" << endl;
	cin >> x;
	
	cout << "fibonacci(" << x << ") = " << fibonacci(x) << endl;
	
	system ("pause");
	return 0;
}

int fibonacci(int number)
{
	int temp = 0;
	int answer1 = 0;
	int answer2 = 1;
	
	if (number == 0)
		return 0;
		
	if (number == 1)
		return 1;
		
	for (int counter = 2; counter <= number; counter++)
	{
		if (number != 0 || 1)		
		{
			temp = answer2; //temporary save answer2
			answer2 = answer2 + answer1;
			answer1 = temp;			  
		}
	}
	
	return answer2;
}
