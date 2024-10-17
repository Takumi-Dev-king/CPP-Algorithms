/*
Kruskal's Algorithm

Kruskal's algorithm finds the Minimum Spanning Tree (MST) for a connected, weighted graph.
It sorts all edges and adds them one by one to the MST if they don't form a cycle.

Time Complexity: O(E log E) due to sorting edges.

Space Complexity: O(V) for the parent array in the union-find structure.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Find function for union-find
int find(int u, vector<int> &parent)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u], parent); // Path compression
    }
    return parent[u];
}

// Union function for union-find
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU; // Attach smaller tree under larger tree
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++; // Increase rank if they are equal
        }
    }
}

// Function to perform Kruskal's algorithm
void kruskal(int V, vector<Edge> &edges)
{
    vector<Edge> mst; // Store the result
    vector<int> parent(V), rank(V, 0);

    // Initialize the union-find structure
    for (int i = 0; i < V; ++i)
    {
        parent[i] = i;
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end(), compare);

    // Process each edge
    for (auto &edge : edges)
    {
        int u = edge.u, v = edge.v, weight = edge.weight;
        if (find(u, parent) != find(v, parent))
        {
            mst.push_back(edge);          // Include in MST
            unionSet(u, v, parent, rank); // Union the sets
        }
    }

    // Print the MST edges
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto &edge : mst)
    {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
}

int main()
{
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}}; // Sample graph edges

    cout << "Kruskal's Algorithm:" << endl;
    kruskal(V, edges); // Run Kruskal's algorithm

    return 0;
}
