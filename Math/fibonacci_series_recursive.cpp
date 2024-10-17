/*
Fibonacci Series (Recursive)

The Fibonacci series is a sequence where each number is the sum of the two preceding ones.
This implementation uses recursion to calculate the nth Fibonacci number.

Time Complexity: O(2^n) due to the overlapping subproblems.

Space Complexity: O(n) due to the recursion stack.
*/

#include <iostream>

using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 0)
        return 0; // Base case: Fibonacci(0) = 0
    if (n == 1)
        return 1;                               // Base case: Fibonacci(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}

int main()
{
    int n = 10; // Find the 10th Fibonacci number
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
