// Implement Merge Sort (The program should report the number of comparisons)
#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int comparisons = 0;

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return comparisons;
}

int mergeSort(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        comparisons += merge(arr, left, mid, right);
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

    int comparisons = mergeSort(arr, 0, n - 1);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}

