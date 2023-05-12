//Implement Heap Sort(The program should report the number of comparisons)
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int& comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        comparisons++;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        comparisons++;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int& comparisons) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
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

    int comparisons = 0;
    heapSort(arr, n, comparisons);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}

