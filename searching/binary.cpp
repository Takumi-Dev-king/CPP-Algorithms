// Binary search is a much more efficient algorithm than linear search but works only on sorted arrays. 
// It divides the search space in half after each comparison, significantly reducing the number of elements to search through.
// Time Complexity:
// Best case: O(1)
// Worst case: O(log n)
// Average case: O(log n)
// Space Complexity:
// Iterative version: O(1)
// Recursive version: O(log n)

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore the left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the element is not present, return -1
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;  // Element to search

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index " << result << endl;

    return 0;
}
