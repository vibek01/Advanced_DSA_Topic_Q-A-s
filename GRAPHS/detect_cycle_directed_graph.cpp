#include <bits/stdc++.h>
using namespace std;

bool dfsCycleDirected(int vertex, vector<bool>& visited, vector<bool>& recursionStack, vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    recursionStack[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            if (dfsCycleDirected(neighbor, visited, recursionStack, adjacencyList)) {
                return true;
            }
        } else if (recursionStack[neighbor]) {
            return true;
        }
    }
    recursionStack[vertex] = false;
    return false;
}

bool hasCycleDirected(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numVertices, false);
    vector<bool> recursionStack(numVertices, false);
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            if (dfsCycleDirected(vertex, visited, recursionStack, adjacencyList)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int vertices = 4;
    vector<vector<int>> adjacencyList(vertices);
    adjacencyList[0].push_back(1);
    adjacencyList[0].push_back(2);
    adjacencyList[1].push_back(2);
    adjacencyList[2].push_back(0);
    adjacencyList[2].push_back(3);
    adjacencyList[3].push_back(3);
    cout << (hasCycleDirected(vertices, adjacencyList) ? "Cycle Detected" : "No Cycle");
    return 0;
}
