//
// Created by MANAN on 24/10/24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's Algorithm to find the shortest path from the source node to all other nodes
void dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj) {
vector<int> dist(n, INT_MAX); // Distance array initialized to infinity (INT_MAX)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue

dist[src] = 0; // Distance from source to itself is 0
pq.push({0, src}); // Push the source node to the priority queue

while (!pq.empty()) {
int u = pq.top().second; // Extract node with the smallest distance
pq.pop();

// Explore all adjacent nodes of node u
for (auto& edge : adj[u]) {
int v = edge.first;  // Adjacent node
int weight = edge.second;  // Weight of the edge between u and v

// Relaxation step: If there's a shorter path to v through u, update it
if (dist[u] + weight < dist[v]) {
dist[v] = dist[u] + weight;  // Update distance to v
pq.push({dist[v], v});  // Push the updated distance to the priority queue
}
}
}

// Print the shortest distances from the source to each node
for (int i = 0; i < n; i++) {
if (dist[i] == INT_MAX) {
cout << "Distance from " << src << " to " << i << " is INF (Unreachable)" << endl;
} else {
cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
}
}
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n); // Adjacency list to represent the graph

    // Add edges to the graph (u, v, w) where u -> v with weight w
    adj[0].push_back({1, 10});
    adj[0].push_back({3, 5});
    adj[1].push_back({2, 1});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 9});
    adj[3].push_back({4, 2});
    adj[4].push_back({0, 7});
    adj[4].push_back({2, 6});

    int src = 0; // Source node
    dijkstra(src, n, adj); // Run Dijkstra's algorithm from source node 0

    return 0;
}