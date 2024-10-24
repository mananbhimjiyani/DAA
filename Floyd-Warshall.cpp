#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Floyd-Warshall algorithm to find all pairs shortest paths
void floydWarshall(int n, vector<vector<int>>& graph) {
    // Initialize the distance matrix with the input graph
    vector<vector<int>> dist = graph;

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) { // Intermediate node
        for (int i = 0; i < n; i++) { // Starting node
            for (int j = 0; j < n; j++) { // Ending node
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Update the shortest path
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "The shortest distances between every pair of vertices are:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4; // Number of vertices in the graph

    // Graph representation as a 2D matrix, where graph[i][j] is the weight of the edge from vertex i to j.
    // If there is no edge between i and j, the weight is set to INT_MAX (infinity).
    vector<vector<int>> graph = {
            {0, 3, INT_MAX, 5},
            {2, 0, INT_MAX, 4},
            {INT_MAX, 1, 0, INT_MAX},
            {INT_MAX, INT_MAX, 2, 0}
    };

    // Call Floyd-Warshall algorithm
    floydWarshall(n, graph);

    return 0;
}