#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//(c) Compute the value of e^x
	double num = 1, ans = 1, fac = 1, x = 1, y = 1, counter = 1,power;
	cout << "Please enter the desired x for the estimation of e^x: " << endl;
	//The number of terms will be one more than the desired x.
	cin >> x;
	
	while (x < 0)
		{
			cout << "The number you entered is negative. Please reenter:" << endl;
			cin >> x;
		} 
	power = x;
	while (counter <= power)
	{	
		while (num <= x)
		{
			fac = fac * num;
			y = power * y;
			num++;
			
		}
		ans = ans + y / fac;
		fac = 1;
		num = 1;
		y = 1;
		counter++;
		x--;
	}
	
	cout << "The estimated value of e is " << ans << "." << endl;
	 
	system ("pause");
	return 0;
}
