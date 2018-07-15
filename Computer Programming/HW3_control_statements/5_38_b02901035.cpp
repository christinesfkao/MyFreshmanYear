//5.38 Towers of Hanoi (Recursive form)

#include <iostream>
#include <stdlib.h>

using namespace std;

void hanoi(int, int, int, int);//function prototype

int main()
{
	int plate = 0;
	
	cout << "Please enter the desired number of plates you wish to move:" << endl;
	cin >> plate;
	
	cout << "The solution for a \"Towers of Hanoi\" problem is to move the plates according to the following sequence:" << endl;
	hanoi(plate, 1, 3, 2);
	
	system("pause");
	return 0;
}

void hanoi(int move, int org, int dest, int temp)
{
	if (move == 1)
		cout << org << " => " << dest << endl;
		
	else
	{	
		hanoi (move - 1, org, temp, dest);
		hanoi (1, org, dest, temp);
		hanoi (move - 1, temp, dest, org);
	}	
}
