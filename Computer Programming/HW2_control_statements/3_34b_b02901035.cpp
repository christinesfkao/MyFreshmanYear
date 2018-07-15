#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//(b) Estimate the value of the mathmatical constant "e"
	int term, num;
	double ans = 1, fac = 1;
	cout << "Please enter the desired number of terms for the estimation of e: " << endl;
	cin >> term;
	
	if (term == 0)
		ans = 0;
	
	while (term < 0)
		{
			cout << "The number you entered is negative. Please reenter:" << endl;
			cin >> term;
		} 
		
	term = term - 1;
		
	num = term;
		
	while (term > 0)
	{	
		while (num > 0)
		{
			fac = fac * num;
			num--;
		}
		term--;
		ans = ans + 1 / fac;
		fac = 1; 
		num = term;
	}
	
	cout << "The estimated value of e is " << ans << "." << endl;
	 
	system ("pause");
	return 0;
}
