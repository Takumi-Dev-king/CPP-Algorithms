// Linear search is a simple algorithm that checks each element in the array sequentially
//  until the desired element is found or the array is fully traversed.
//  Time Complexity:
// Best case: O(1)
// Worst case: O(n)
// Average case: O(n)
// Space Complexity:
// O(1)

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // If the element is not found, return -1
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int x = 1;  // Element to search
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    
    return 0;
}
