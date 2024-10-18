/*
Fractional Knapsack

The Fractional Knapsack problem aims to maximize the total value of items placed in a knapsack of limited capacity.
Unlike the 0/1 Knapsack, we can take fractions of items.

Time Complexity: O(n log n) due to sorting the items by value/weight ratio.

Space Complexity: O(1) as no additional space is used apart from input.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Item structure
struct Item
{
    int value, weight;
};

// Comparator function to sort items by value/weight ratio
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate maximum value in Fractional Knapsack
double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare); // Sort by value/weight ratio

    double totalValue = 0.0;
    for (auto &item : items)
    {
        if (capacity >= item.weight)
        {
            totalValue += item.value; // Take the whole item
            capacity -= item.weight;
        }
        else
        {
            totalValue += item.value * ((double)capacity / item.weight); // Take fraction
            break;
        }
    }
    return totalValue; // Return maximum value
}

int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;
    return 0;
}
