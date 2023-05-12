//bucket sort
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
	// 1) Create n empty buckets
	vector<float> b[n];
	// 2) Put array elements in different buckets
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		// Index in bucket
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

void display(float *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

/* Driver program to test above function */
int main()
{
	int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   bucketSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
