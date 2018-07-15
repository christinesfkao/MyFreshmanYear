#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void quickSort (int * const, int, int);
int partition (int * const, int, int);
void swap (int * const, int * const);

int main()
{
	const int arraySize = 10;
	int a[arraySize] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
	
	cout << "Data items in original order:" << endl;
	
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
		
	quickSort (a, arraySize - 1, 0);
	
	cout << endl << "Data items in ascending order:" << endl;
	
	for (int j = 0; j < arraySize; j++)
		cout << setw(4) << a[j];
	
	cout << endl;
	
	
	system ("pause");
	return 0;
} 

void quickSort (int * const array, int end, int start)
{
	if (start >= end)
		return;
		
	int target = partition (array, end, start);
	quickSort (array, target - 1, start);
	quickSort (array, end, target + 1);
		
}

int partition (int * const array, int right, int left)
{
	int target = left;
	
	for (;right > left; right--)
	{
		if (array[right] < array[target])
		{
			swap (&array[right], &array[target]);
			target = right;
			left++;
			break;
		}
	}
	
	for (;right > left; left++)
	{
		if (array[left] > array[target])
		{
			swap (&array[left], &array[target]);
			target = left;
			right--;
			break;
		}
	}	
	
	if( right <= left)
		return target;
	else
		return partition (array, right, left);
	
}

void swap (int * const item1Ptr, int * const item2Ptr)
{
	int hold = *item1Ptr;
	*item1Ptr = *item2Ptr;
	*item2Ptr = hold;
}
