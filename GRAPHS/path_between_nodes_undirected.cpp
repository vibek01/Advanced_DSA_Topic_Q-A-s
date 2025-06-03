#include <bits/stdc++.h>
using namespace std;

bool dfsPathExists(int currentVertex, int targetVertex, vector<bool>& visited, vector<vector<int>>& adjacencyList) {
    if (currentVertex == targetVertex) {
        return true;
    }
    visited[currentVertex] = true;
    for (int neighbor : adjacencyList[currentVertex]) {
        if (!visited[neighbor]) {
            if (dfsPathExists(neighbor, targetVertex, visited, adjacencyList)) {
                return true;
            }
        }
    }
    return false;
}

bool pathExists(int numVertices, vector<vector<int>>& adjacencyList, int source, int destination) {
    vector<bool> visited(numVertices, false);
    return dfsPathExists(source, destination, visited, adjacencyList);
}

int main() {
    int vertices = 6;
    vector<vector<int>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    cout << (pathExists(vertices, adjacencyList, 0, 5) ? "Path Exists" : "No Path");
    return 0;
}
