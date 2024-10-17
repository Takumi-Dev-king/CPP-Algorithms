/*
Moore's Voting Algorithm

This algorithm is used to find the majority element in an array,
which is an element that appears more than n/2 times.

Time Complexity: O(n) for the traversal of the array.

Space Complexity: O(1) since it uses a constant amount of space.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find the majority element
int mooreVoting(const vector<int> &arr)
{
    int candidate = -1; // Initialize candidate
    int count = 0;      // Initialize count

    // Phase 1: Find a candidate for majority element
    for (int num : arr)
    {
        if (count == 0)
        {
            candidate = num; // Set candidate to the current number
        }
        count += (num == candidate) ? 1 : -1; // Increase or decrease count
    }

    // Phase 2: Verify if the candidate is the majority element
    count = 0; // Reset count
    for (int num : arr)
    {
        if (num == candidate)
        {
            count++;
        }
    }
    return (count > arr.size() / 2) ? candidate : -1; // Return candidate if valid
}

int main()
{
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4}; // Sample array
    int majorityElement = mooreVoting(arr);

    if (majorityElement != -1)
    {
        cout << "Majority element is: " << majorityElement << endl;
    }
    else
    {
        cout << "No majority element found." << endl;
    }
    return 0;
}
