#include <bits/stdc++.h>
using namespace std;

void dfsComponent(int vertex, vector<bool>& visited, vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            dfsComponent(neighbor, visited, adjacencyList);
        }
    }
}

int countConnectedComponents(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numVertices, false);
    int componentCount = 0;
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            componentCount++;
            dfsComponent(vertex, visited, adjacencyList);
        }
    }
    return componentCount;
}

int main() {
    int vertices = 8;
    vector<vector<int>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(3, 4);
    addEdge(5, 6);
    addEdge(5, 7);
    cout << countConnectedComponents(vertices, adjacencyList);
    return 0;
}
