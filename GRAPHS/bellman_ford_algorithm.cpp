#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u;
    int v;
    int weight;
};

vector<int> bellmanFordShortestPath(int source, int numVertices, vector<Edge>& edges) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;
    for (int i = 1; i < numVertices; i++) {
        for (Edge edge : edges) {
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }
    for (Edge edge : edges) {
        if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
            // Negative cycle detected; distances may be invalid
        }
    }
    return distance;
}

int main() {
    int vertices = 5;
    vector<Edge> edges;
    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});
    vector<int> distances = bellmanFordShortestPath(0, vertices, edges);
    for (int i = 0; i < vertices; i++) {
        cout << "Distance to " << i << ": " << distances[i] << "\n";
    }
    return 0;
}
