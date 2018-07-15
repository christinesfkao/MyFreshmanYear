//HW5.39 Towers of Hanoi (Iterative form)

#include <iostream>
#include <stdlib.h>
#include <cmath>// will use the function "pow"

using namespace std;

double pow(double , int);

int main()
{	
	double number;
	int plate;
	int step = pow(2.0, number) - 1;
	int peg1[plate], peg2[plate], peg3[plate];
	int small1 = plate - 1, small2 = 0, small3 = 0;
	
	cout << "Please enter the desired number of plates you wish to move:" << endl;
	cin >> number;
	
	plate = number;
	
	for (int x = 0 ; x < plate ; x++ )// assign values for the declared arrays
	{
		peg1[x] = number;
		number--;
				
		peg2[x] = plate + 1;
		peg3[x] = plate + 1;
			}
	
	
		
	if (plate % 2 == 1)//A <=> C, A <=> B, B <=> C
	{
		for (int i = 1; i <= step; i++)
		{
			if (i % 3 == 1)//A <=> C
			{
				if (peg1[small1] < peg3[small3]) 
				{
					peg3[small3] = peg1[small1];
					peg1[small1] = plate + 1;
					small1--;
					small3++;
				
					cout << "1 => 3" << endl;
				}
				else
				{
					peg1[small1] = peg3[small3];
					peg3[small3] = plate + 1;
					small3--;
					small1++;
				
					cout << "3 => 1" << endl;
				}	
			}
			
			if (i % 3 == 2)//A <=> B
			{
				if (peg1[small1] < peg2[small2]) 
				{
					peg2[small2] = peg1[small1];
					peg1[small1] = plate + 1;
					small1--;
					small2++;
				
					cout << "1 => 2" << endl;
				}
				else
				{
					peg1[small1] = peg2[small2];
					peg2[small2] = plate + 1;
					small2--;
					small1++;
				
					cout << "2 => 1" << endl;
				}	
			}
			
			if (i % 3 == 0)//B <=> C
			{
				if (peg2[small2] < peg3[small3]) 
				{
					peg3[small3] = peg2[small2];
					peg2[small2] = plate + 1;
					small2--;
					small3++;
				
					cout << "2 => 3" << endl;
				}
				else
				{
					peg2[small2] = peg3[small3];
					peg3[small3] = plate + 1;
					small3--;
					small2++;
				
					cout << "3 => 2" << endl;
				}	
			}
			
		}
	}
	else //A <=> B, A <=> C, B <=> C	
	{
		for (int i = 1; i <= step; i++)
		{
			if (i % 3 == 1)//A <=> B
			{
				if (peg1[small1] < peg2[small2]) 
				{
					peg2[small2] = peg1[small1];
					peg1[small1] = plate + 1;
					small1--;
					small2++;
				
					cout << "1 => 2" << endl;
				}
				else
				{
					peg1[small1] = peg2[small2];
					peg2[small2] = plate + 1;
					small2--;
					small1++;
				
					cout << "2 => 1" << endl;
				}	
			}
			
			if (i % 3 == 2)//A <=> C
			{
				if (peg1[small1] < peg3[small3]) 
				{
					peg3[small3] = peg1[small1];
					peg1[small1] = plate + 1;
					small1--;
					small3++;
				
					cout << "1 => 3" << endl;
				}
				else
				{
					peg1[small1] = peg3[small3];
					peg3[small3] = plate + 1;
					small3--;
					small1++;
				
					cout << "3 => 1" << endl;
				}		
			}
			
			if (i % 3 == 0)//B <=> C
			{
				if (peg2[small2] < peg3[small3]) 
				{
					peg3[small3] = peg2[small2];
					peg2[small2] = plate + 1;
					small2--;
					small3++;
				
					cout << "2 => 3" << endl;
				}
				else
				{
					peg2[small2] = peg3[small3];
					peg3[small3] = plate + 1;
					small3--;
					small2++;
				
					cout << "3 => 2" << endl;
				}	
			}
			
		}
	}	

	system("pause");
	return 0;
}

