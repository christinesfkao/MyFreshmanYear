#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	int num = 1, ans = 1;
	
	for (; num <=5; num++)
	{	
		ans = ans * num;
		cout << num << "! = " << setw (3) << ans << endl; 
	}
	
	cout << endl;
	
	long int answer = 1;
	// if you use "int" for declaration, the answer turns out to be negative because there isn't enough space to hold 20!. 
	num = 1;
		
	for (; num <= 20; num++)
		ans = ans * num;
	
	cout << "20! = " << ans << endl; 
	
	system ("pause");
	return 0;
}
