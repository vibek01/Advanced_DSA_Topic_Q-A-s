#include <bits/stdc++.h>
using namespace std;

bool dfsCycleUndirected(int currentVertex, int parentVertex, vector<bool>& visited, vector<vector<int>>& adjacencyList) {
    visited[currentVertex] = true;
    for (int neighbor : adjacencyList[currentVertex]) {
        if (!visited[neighbor]) {
            if (dfsCycleUndirected(neighbor, currentVertex, visited, adjacencyList)) {
                return true;
            }
        } else if (neighbor != parentVertex) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirected(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numVertices, false);
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            if (dfsCycleUndirected(vertex, -1, visited, adjacencyList)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int vertices = 5;
    vector<vector<int>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 1);
    cout << (hasCycleUndirected(vertices, adjacencyList) ? "Cycle Detected" : "No Cycle");
    return 0;
}
