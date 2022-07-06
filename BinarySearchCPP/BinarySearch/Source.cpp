#include <iostream>

#define ERROR (-1)

//Binary Search
int binarySearch(uint32_t arr[], int leftIndex, int rightIndex, uint32_t value)
{
	//Check Exit Condition of Indices
	if (rightIndex >= leftIndex)
	{
		//Find Midpoint
		int mid = leftIndex + (rightIndex - leftIndex) / 2;

		//Check Midpoint		
		if (arr[mid] == value)
			return mid;

		//Check if value at mid is larger than value.  Value equal to mid handled above
		if (arr[mid] > value)
		{
			//Recursive Call if present on left side of array
			return binarySearch(arr, leftIndex, mid - 1, value);
		}
		else
		{
			//Recursive Call if present on right side of array
			return binarySearch(arr, mid + 1, rightIndex, value);
		}

	}
	else
	{
		//Return "Error"
		return ERROR;
	}
}

int main(void)
{
	//Local Variables
	uint32_t arr[] = { 2, 3, 4,6, 8, 9, 10,20,30 ,40,42,43 }; //Sorted Array
	uint32_t x = 0;
	uint32_t n = sizeof(arr) / sizeof(arr[0]);

	//Binary Search Call( array, left index, right index, value)
	int result = binarySearch(arr, 0, n - 1, x);

	if (result == ERROR)
	{
		std::cout << "Element is not present in array" << std::endl;
	}
	else
	{
		std::cout << "Element " << x << " is present at index " << result << std::endl;

	}

	return 0;
}
