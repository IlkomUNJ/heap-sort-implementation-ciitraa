#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array
void buildMaxHeap(int arr[], int n) {
    // Index of last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    cout << "Max Heap: ";
    printArray(arr, n);

    return 0;
}
