// C++ implementation Randomized Quick-Sort
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and
 places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition(int arr[], int low, int high)
{
	// pivot
	int pivot = arr[high];

	// Index of smaller element
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or equal to pivot
		if (arr[j] <= pivot) {

			// increment index of smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// Generate a random number in between low to high
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		/* pi is partitioning index,
		arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}


int main()
{
   int n;
   cout << "--------RANDOMIZED QUICK SORT---------\n";
   cout << "\nEnter the number of elements: ";
   cin >> n;
   int arr[n];
   //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   quickSort(arr, 0, n - 1);
   cout << "Array after Sorting: ";
   display(arr, n);
   return 0;
}
