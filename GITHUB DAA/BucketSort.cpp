// Implement Bucket Sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int getMax(int a[], int n) // function to get maximum element from the given array
{
 int max = a[0];
 for (int i = 1; i < n; i++)
 if (a[i] > max)
 max = a[i];
 return max;
}
void bucket(int a[], int n) // function to implement bucket sort
{
 int max = getMax(a, n); //max is the maximum element of array
 int bucket[max], i;
 for (int i = 0; i <= max; i++)
 {
 bucket[i] = 0;
 }
 for (int i = 0; i < n; i++)
 {

 bucket[a[i]]++;
 }
 for (int i = 0, j = 0; i <= max; i++)
 {
 while (bucket[i] > 0)
 {
 a[j++] = i;
 bucket[i]--;
 }
 }
}
/* Function to print an array */
void display(int *array, int size) {
 for(int i = 0; i<size; i++)
 cout << array[i] << " ";
 cout << endl;
}
/* Driver program to test above function */
int main()
{
 int n;
 cout << "--------BUCKET SORT---------\n";
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
 bucket(arr, n);
 cout << "Array after Sorting: ";
 display(arr, n);
 return 0;
}
/*int comparisons = 0;
    bucketSort(arr, n, comparisons);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;*/

