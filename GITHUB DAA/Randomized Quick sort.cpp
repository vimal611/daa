//Implement Randomized Quick sort (The program should report the number of comparisons)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }

    swap(arr[i + 1], arr[high]);
    comparisons++;
    return (i + 1);
}

int randomizedPartition(int arr[], int low, int high, int& comparisons) {
    srand(time(NULL));
    int randomIndex = low + rand() % (high - low);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high, comparisons);
}

void quickSort(int arr[], int low, int high, int& comparisons) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
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
    quickSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}

