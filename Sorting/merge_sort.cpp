/*
Merge Sort Algorithm

The array is recursively divided into halves until single elements remain,
then merged back in sorted order.

Time Complexity: O(n log n) for all cases due to the divide and conquer approach.

Space Complexity: O(n) because of the temporary arrays used for merging.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves of an array
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    vector<int> L(n1), R(n2); // Temporary arrays for merging

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i]; // Copy left subarray
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j]; // Copy right subarray
    }

    // Merge the temporary arrays back into arr
    int i = 0, j = 0, k = left; // Indices for L, R, and merged array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++]; // If L[i] is smaller, add it to arr
        } else {
            arr[k++] = R[j++]; // If R[j] is smaller, add it to arr
        }
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Function to implement Merge Sort
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the mid point
        mergeSort(arr, left, mid);            // Sort first half
        mergeSort(arr, mid + 1, right);       // Sort second half
        merge(arr, left, mid, right);          // Merge the sorted halves
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10}; // Sample array
    mergeSort(arr, 0, arr.size() - 1); // Sort the array
    cout << "Sorted array: ";
    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
