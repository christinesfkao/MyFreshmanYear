#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int num;
	
	cout << "Please enter a number: ";
	cin >> num;
	
	if (num%2 == 0)
		cout << num << " is an even number.";
	else
		cout << num << " is a odd number.";
		
	system ("pause");
	return 0;
}
