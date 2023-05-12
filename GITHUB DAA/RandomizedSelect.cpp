//Implement Randomized Select
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int l, int r, int& comparisons) {
    int pivotIndex = l + rand() % (r - l + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[r]);

    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivotValue) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
        comparisons++;
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int randomizedSelect(int arr[], int l, int r, int k, int& comparisons) {
    if (l == r) {
        return arr[l];
    }
    int q = partition(arr, l, r, comparisons);
    int leftSize = q - l + 1;

    if (k == leftSize) {
        return arr[q];
    }
    else if (k < leftSize) {
        return randomizedSelect(arr, l, q - 1, k, comparisons);
    }
    else {
        return randomizedSelect(arr, q + 1, r, k - leftSize, comparisons);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k (1 <= k <= " << n << "): ";
    cin >> k;

   // srand(time(nullptr));
    int comparisons = 0;
    int kthSmallest = randomizedSelect(arr, 0, n - 1, k, comparisons);

    cout << "The " << k << "th smallest element in the array is: " << kthSmallest << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

