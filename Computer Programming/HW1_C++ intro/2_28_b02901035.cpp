#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int num, num1, num2, num3, num4, num5;
	
	cout << "Please enter a five-digit integer: ";
	cin >> num;
	
	num1 = num / 10000;
	num2 = num / 1000 - num1*10;
	num3 = num / 100 - num1*100 - num2*10;
	num5 = num % 10;
	num4 = (num % 100 - num5) / 10;
	
	cout << num1 << "   " << num2 << "   " << num3 << "   " << num4 << "   " << num5 << endl;
	
	
	system ("pause");
	return 0;
}
