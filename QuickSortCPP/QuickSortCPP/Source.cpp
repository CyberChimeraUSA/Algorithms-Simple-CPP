#include <iostream>

using namespace std;

//Swap Values
void swap(uint32_t* a, uint32_t* b)
{
	uint32_t temp = *a;
	*a = *b;
	*b = temp;
}

// Function to print an array 
void printArray(uint32_t arr[], uint32_t size)
{
	cout << "printArray\n";

	for (uint32_t i = 0; i < size; i++)
		cout << arr[i] << ", ";

	cout << "\n\n";
}

//Pivot
uint32_t pivot(uint32_t arr[], uint32_t indexLow, uint32_t indexHigh)
{
	//Algorithm Pivots around High Index
	uint32_t pivotIndex = arr[indexHigh];

	int i = indexLow - 1;
	int j = indexLow;

	//Loop Through with J
	for (j = indexLow; j <= indexHigh - 1; j++)
	{
		if (arr[j] < pivotIndex)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[indexHigh]);

	return (i + 1);
}

//Quicksort
void quicksort(uint32_t arr[], uint32_t indexLow, uint32_t indexHigh)
{
	if (indexLow < indexHigh)
	{

		//Find Pivot
		uint32_t pivotIndex = pivot(arr, indexLow, indexHigh);

		//Quicksort Left
		quicksort(arr, indexLow, pivotIndex - 1);

		//Quicksort Right
		quicksort(arr, pivotIndex + 1, indexHigh);
	}
}


int main(void)
{
	//Allocate
	uint32_t arrUnderTest[] = { 90, 60, 30, 40, 80, 10, 70, 20, 50, 100 };

	//size of Array (40) / size of uint32_t (4) -> 10
	uint32_t sizeOfArray = sizeof(arrUnderTest) / sizeof(arrUnderTest[0]);

	//Print Unsorted Array
	printArray(arrUnderTest, sizeOfArray);

	//Max Index of Array
	uint32_t maxIndex = sizeOfArray - 1;

	//Quicksort
	quicksort(arrUnderTest,0,maxIndex);

	//Print Sorted Array
	printArray(arrUnderTest, sizeOfArray);

}
