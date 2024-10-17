/*
Kadane's Algorithm

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray
in an array of integers.

Time Complexity: O(n) as it makes a single pass through the array.

Space Complexity: O(1) since it uses a constant amount of space.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum sum of a contiguous subarray
int kadane(const vector<int> &arr)
{
    int maxSoFar = arr[0];      // Initialize max sum
    int maxEndingHere = arr[0]; // Initialize current max

    // Traverse through the array
    for (int i = 1; i < arr.size(); ++i)
    {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]); // Update current max
        maxSoFar = max(maxSoFar, maxEndingHere);             // Update overall max
    }
    return maxSoFar; // Return the maximum sum found
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Sample array
    int maxSum = kadane(arr);                          // Find maximum sum of contiguous subarray
    cout << "Maximum sum of contiguous subarray is: " << maxSum << endl;
    return 0;
}
