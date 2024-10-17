/*
Insertion Sort Algorithm

Insertion Sort builds a sorted array one element at a time.
It is much less efficient on large lists than more advanced algorithms.

Time Complexity: O(n²) for all cases.

Space Complexity: O(1) since it sorts the array in place.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    // Traverse through 1 to n
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i]; // Element to be inserted
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place key at the correct position
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6}; // Sample array
    insertionSort(arr);                   // Sort the array
    cout << "Sorted array: ";
    // Print sorted array
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}
