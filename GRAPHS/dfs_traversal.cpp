#include <bits/stdc++.h>
using namespace std;

void depthFirstSearch(int vertex, vector<bool>& visited, vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            depthFirstSearch(neighbor, visited, adjacencyList);
        }
    }
}

void dfsTraversal(int startVertex, vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();
    vector<bool> visited(numVertices, false);
    depthFirstSearch(startVertex, visited, adjacencyList);
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
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);
    dfsTraversal(0, adjacencyList);
    return 0;
}
