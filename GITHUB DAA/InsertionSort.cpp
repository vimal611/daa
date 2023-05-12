// Implement Insertion Sort (The program should report the number of comparisons)
#include <iostream>
using namespace std;

int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = insertionSort(arr, n);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}

