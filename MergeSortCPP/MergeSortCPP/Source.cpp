#include <iostream>
#include <vector>
#include <string>

#define DEBUG
#undef DEBUG

using namespace std;

#ifdef DEBUG
uint32_t maxIndexGlobal = 0;
#endif
// Function to print an array 
void printArray(uint32_t arr[], uint32_t size)
{
	cout << "printArray\n";

	for (uint32_t i = 0; i < size; i++)
		cout << arr[i] << ", ";

	cout << "\n\n";
}

#ifdef DEBUG
// Function to print an array 
void printArray(uint32_t arr[], uint32_t size, string text)
{
	cout << text << "\n";

	for (uint32_t i = 0; i < size; i++)
		cout << arr[i] << ", ";

	cout << "\n\n";
}
#endif
//Merge
void merge(uint32_t arr[], uint32_t leftIndex, uint32_t midIndex, uint32_t rightIndex)
{
	//Local Variables
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t k = leftIndex;
	uint32_t n1 = midIndex - leftIndex + 1;
	uint32_t n2 = rightIndex - midIndex;

	//Create Temp Vectors
	vector <uint32_t>  tempL(n1);
	vector <uint32_t>  tempR(n2);

	//Copy to Temp Left Array
	for (i = 0; i < n1; i++)
	{
		tempL[i] = arr[leftIndex + i];
	}

	//Copy to Temp Right Array
	for (j = 0; j < n2; j++)
	{
		tempR[j] = arr[midIndex + 1 + j];
	}

	//Reset Indices 
	i = 0; 
	j = 0; 
	k = leftIndex;

	//Copy Until we reach first indice limit
	while (i < n1 && j < n2) 
	{
		if (tempL[i] <= tempR[j])
		{
			arr[k] = tempL[i];
			i++;
		}
		else {
			arr[k] = tempR[j];
			j++;
		}
		k++;
	}

	//Copy until we reach other limit
	while (i < n1) 
	{
		arr[k] = tempL[i];
		i++;
		k++;
	}

	//Copy until we reach other limit
	while (j < n2) 
	{
		arr[k] = tempR[j];
		j++;
		k++;
	}
}

//Merge Sort
void mergeSort(uint32_t arr[], uint32_t leftIndex, uint32_t rightIndex)
{
	if (leftIndex < rightIndex)
	{

		uint32_t middle = leftIndex + (rightIndex - leftIndex) / 2;

		// Break Down First and Second Halves
		mergeSort(arr, leftIndex, middle);
		mergeSort(arr, middle + 1, rightIndex);
#ifdef DEBUG
		printArray(arr, maxIndexGlobal + 1, "Before");
#endif
		//Merge
		merge(arr, leftIndex, middle, rightIndex);

		/*
			Merge 1: 60, 90, 30, 40, 80, 10, 70, 20, 50, 100-->Left:0 Middle:0 Right:1
			Merge 2: 30, 60, 90, 40, 80, 10, 70, 20, 50, 100-->Left:0 Middle:1 Right:2
			Merge 3: 30, 60, 90, 40, 80, 10, 70, 20, 50, 100-->Left:3 Middle:3 Right:4
			Merge 4: 30, 40, 60, 80, 90, 10, 70, 20, 50, 100-->Left:0 Middle:2 Right:4
			Merge 5: 30, 40, 60, 80, 90, 10, 70, 20, 50, 100-->Left:5 Middle:5 Right:6
			Merge 6: 30, 40, 60, 80, 90, 10, 20, 70, 50, 100-->Left:5 Middle:6 Right:7
			Merge 7: 30, 40, 60, 80, 90, 10, 20, 70, 50, 100-->Left:8 Middle:8 Right:9
			Merge 8: 30, 40, 60, 80, 90, 10, 20, 50, 70, 100-->Left:5 Middle:7 Right:9
			Merge 9: 10, 20, 30, 40, 50, 60, 70, 80, 90, 100-->Left:0 Middle:4 Right:9
		*/

#ifdef DEBUG
		printArray(arr, maxIndexGlobal + 1, "After");
#endif
	}
}


int main()
{
	//Allocate
	uint32_t arrUnderTest[] = { 90, 60, 30, 40, 80, 10, 70, 20, 50, 100 };

	//size of Array (40) / size of uint32_t (4) -> 10
	uint32_t sizeOfArray = sizeof(arrUnderTest) / sizeof(arrUnderTest[0]);

	//Print Unsorted Array
	printArray(arrUnderTest, sizeOfArray);

	//Max Index of Array
	uint32_t maxIndex = sizeOfArray - 1;

#ifdef DEBUG
	maxIndexGlobal = maxIndex;
#endif
	mergeSort(arrUnderTest, 0, maxIndex);


	//Print Sorted Array
	printArray(arrUnderTest, sizeOfArray);

	return 0;
}
