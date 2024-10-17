/*
Depth-First Search (DFS)

DFS is an algorithm for traversing or searching tree or graph data structures.
Starting from a source node, it explores as far as possible along each branch
before backtracking.

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity: O(V) for the recursion stack or O(V) for the visited array.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS
void dfs(int v, vector<bool> &visited, const vector<vector<int>> &adj)
{
    visited[v] = true; // Mark the current node as visited
    cout << v << " ";  // Process the current node

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}

int main()
{
    int V = 5;                  // Number of vertices
    vector<vector<int>> adj(V); // Adjacency list representation of the graph

    // Sample graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(V, false); // Visited array
    cout << "DFS Traversal: ";
    dfs(0, visited, adj); // Start DFS from vertex 0
    cout << endl;

    return 0;
}
