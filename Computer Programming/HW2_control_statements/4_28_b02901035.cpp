#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	for (int num = 1; num <= 12; num++)
	{
		cout << "On the ";
		switch (num)
		{
			case 1:
				cout << "first";
				break;
				
			case 2:
				cout << "second";
				break;
				
			case 3:
				cout << "third";
				break;

			case 4:
				cout << "fourth";
				break;
				
			case 5:
				cout << "fifth";
				break;
				
			case 6:
				cout << "sixth";
				break;
																				
			case 7:
				cout << "seventh";
				break;

			case 8:
				cout << "eighth";
				break;
								
			case 9:
				cout << "ninth";
				break;

			case 10:
				cout << "tenth";
				break;

			case 11:
				cout << "eleventh";
				break;
			
			case 12:
				cout << "twelfth";
				break;							
		}
		
		cout << " day of Christmas," << endl << "My true love sent to me," << endl;
	
		switch (num)
		{
			case 12:
				cout << "Twelve drummers drumming," << endl;
				
			case 11:
				cout << "Eleven pipers piping," << endl;
				
			case 10:
				cout << "Ten lords a leaping," << endl;
			
			case 9:
				cout << "Nine ladies danceing," << endl;
			
			case 8:
				cout << "Eight maids a milking," << endl;
			
			case 7:
				cout << "Seven swans a swimming," << endl;
			
			case 6:
				cout << "Six geese a laying," << endl;
			
			case 5:
				cout << "Five golden rings," << endl;
			
			case 4:
				cout << "Four calling birds," << endl;
			
			case 3:
				cout << "Three french hens," << endl;
			
			case 2:
				cout << "Two turtle doves," << endl << "And a partridge in a pear tree." << endl << endl;
				break;
				
			case 1:
				cout << "A partridge in a pear tree." << endl << endl;
			}
	
	}	
	
	system ("pause");
	return 0;
}
