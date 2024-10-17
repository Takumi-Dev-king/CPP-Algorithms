/*
Fibonacci Series Algorithm

The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones.
It starts with 0 and 1.

Time Complexity: O(n) to compute the nth Fibonacci number.

Space Complexity: O(1) since it uses a constant amount of space.
*/

#include <iostream>

using namespace std;

// Function to calculate nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 0)
        return 0; // Base case
    if (n == 1)
        return 1; // Base case

    int a = 0, b = 1, c; // Initialize first two Fibonacci numbers
    for (int i = 2; i <= n; ++i)
    {
        c = a + b; // Calculate the next Fibonacci number
        a = b;     // Update previous numbers
        b = c;
    }
    return b; // Return the nth Fibonacci number
}

int main()
{
    int n = 10; // Find the 10th Fibonacci number
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
