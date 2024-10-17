/*
Dijkstra's Algorithm

Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a graph
with non-negative edge weights.

Time Complexity: O((V + E) log V) using a priority queue.

Space Complexity: O(V) for the distance array.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(int src, const vector < vector<pair<int, int>> & adj)
{
    int V = adj.size();
    vector<int> dist(V, numeric_limits<int>::max()); // Distance from source
    dist[src] = 0;                                   // Distance to the source is 0

    // Min-heap priority queue to store (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Push the source into the queue

    while (!pq.empty())
    {
        int u = pq.top().second; // Vertex with the smallest distance
        pq.pop();

        // Explore all adjacent vertices
        for (auto &edge : adj[u])
        {
            int v = edge.first;       // Adjacent vertex
            int weight = edge.second; // Edge weight

            // Relaxation step
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Update the shortest distance
                pq.push({dist[v], v});      // Push the updated distance into the queue
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int V = 5;                             // Number of vertices
    vector<vector<pair<int, int>>> adj(V); // Adjacency list representation

    // Sample graph edges (u, v, weight)
    adj[0] = {{1, 10}, {2, 3}};
    adj[1] = {{2, 1}, {3, 2}};
    adj[2] = {{1, 4}, {3, 8}, {4, 2}};
    adj[3] = {{4, 7}};
    adj[4] = {};

    cout << "Dijkstra's Algorithm:" << endl;
    dijkstra(0, adj); // Start Dijkstra from vertex 0

    return 0;
}
