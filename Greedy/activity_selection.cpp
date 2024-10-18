/*
Activity Selection

The Activity Selection problem selects the maximum number of activities
that do not overlap, given their start and finish times.

Time Complexity: O(n log n) due to sorting by finish times.

Space Complexity: O(1) as no extra space is required apart from input.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Activity structure
struct Activity
{
    int start, finish;
};

// Comparator function to sort activities by finish time
bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

// Function to select the maximum number of non-overlapping activities
int activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compare); // Sort by finish time

    int count = 1; // Select the first activity
    int lastFinish = activities[0].finish;

    // Iterate through remaining activities
    for (int i = 1; i < activities.size(); ++i)
    {
        if (activities[i].start >= lastFinish)
        { // Non-overlapping condition
            ++count;
            lastFinish = activities[i].finish;
        }
    }
    return count; // Return number of selected activities
}

int main()
{
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int maxActivities = activitySelection(activities);
    cout << "Maximum number of activities: " << maxActivities << endl;
    return 0;
}
