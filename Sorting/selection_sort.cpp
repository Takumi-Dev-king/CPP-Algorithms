/*
Selection Sort Algorithm

Selection Sort is a simple comparison-based sorting algorithm.
It divides the input list into two parts: a sorted and an unsorted part,
and repeatedly selects the smallest (or largest) element from the unsorted part.

Time Complexity: O(n²) for all cases.

Space Complexity: O(1) since it sorts the array in place.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    // Traverse through all elements in the array
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i; // Assume the minimum is the first element
        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // Update minIdx if a smaller element is found
            }
        }
        swap(arr[i], arr[minIdx]); // Swap the found minimum element with the first element
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11}; // Sample array
    selectionSort(arr); // Sort the array
    cout << "Sorted array: ";
    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

