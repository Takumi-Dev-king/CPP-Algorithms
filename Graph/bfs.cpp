/*
Breadth-First Search (BFS)

BFS is an algorithm for traversing or searching tree or graph data structures.
It starts from a source node and explores all of its neighbors at the present depth
before moving on to nodes at the next depth level.

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity: O(V) for the queue used to store the vertices.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, const vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false); // Visited array
    queue<int> q;                            // Queue for BFS

    visited[start] = true; // Mark the start node as visited
    q.push(start);         // Enqueue the start node

    while (!q.empty())
    {
        int v = q.front(); // Dequeue a vertex
        cout << v << " ";  // Process the current vertex
        q.pop();

        // Enqueue all adjacent unvisited vertices
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true; // Mark as visited
                q.push(i);         // Enqueue the adjacent vertex
            }
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

    cout << "BFS Traversal: ";
    bfs(0, adj); // Start BFS from vertex 0
    cout << endl;

    return 0;
}
