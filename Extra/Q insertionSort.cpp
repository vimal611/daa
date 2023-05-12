#include <bits/stdc++.h>
using namespace std;


void insertionSort(int A[], int n)
{
    int i, key, j;
    for (j = 1; j < n; j++)
    {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

}


void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}


int main()
{
    cout<<"---------INSERTION SORT---------\n";
    int A[100],i,j,n;
    cout<<"\nPlease enter no. of elements:- ";
    cin>>n;
    cout<<"\nEnter element:\n";
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    insertionSort(A, n);
    cout<<"Array after sorted:-\n";
    printArray(A, n);
    return 0;
}
