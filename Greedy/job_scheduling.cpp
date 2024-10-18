/*
Job Scheduling (with deadlines)

The Job Scheduling problem with deadlines maximizes total profit
by scheduling jobs such that each job is completed before its deadline.

Time Complexity: O(n log n) due to sorting by profit.

Space Complexity: O(n) for storing job slots.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job structure
struct Job
{
    int id, deadline, profit;
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to schedule jobs for maximum profit
int jobScheduling(vector<Job> &jobs, int maxDeadline)
{
    sort(jobs.begin(), jobs.end(), compare); // Sort jobs by profit

    vector<int> slots(maxDeadline, -1); // Slots for jobs (initialized as empty)
    int totalProfit = 0;

    for (auto &job : jobs)
    {
        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; --j)
        {
            if (slots[j] == -1)
            { // If slot is empty
                slots[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    return totalProfit; // Return total profit
}

int main()
{
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int maxDeadline = 3;
    int maxProfit = jobScheduling(jobs, maxDeadline);
    cout << "Maximum profit = " << maxProfit << endl;
    return 0;
}
