#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
   	 largest = l;

    if (r < N && arr[r] > arr[largest])
   	 largest = r;

    if (largest != i) {
   	 swap(arr[i], arr[largest]);

   	 heapify(arr, N, largest);
    }
}

void buildHeap(int arr[], int N)
{
    int startIdx = (N / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
   	 heapify(arr, N, i);
    }
}

void printHeap(int arr[], int N)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < N; ++i)
   	 cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int N = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, N);
    printHeap(arr, N);
    return 0;
}
