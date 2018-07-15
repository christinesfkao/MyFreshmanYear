#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//(a) Read a nonnegative integer and compute and print its factorial
	int num, ans = 1;
	cout << "Please enter a number for the value of its factorial: " << endl;
	cin >> num;
	
	while (num < 0)
	{	
		cout << "The number you entered is negative. Please reenter." << endl;
		cin >> num;
	}
	
	if (num == 0)
		ans = 1;
	else
	{	
		while (num > 0)
		ans = ans * num;
		num--;
	}
	cout << "The factorial of the number you entered is " << ans << "." << endl;
	
	system ("pause");
	return 0;
}
