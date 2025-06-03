#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int vertex, vector<bool>& visited, stack<int>& topoStack, vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            dfsTopo(neighbor, visited, topoStack, adjacencyList);
        }
    }
    topoStack.push(vertex);
}

vector<int> topologicalSortDFS(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numVertices, false);
    stack<int> topoStack;
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            dfsTopo(vertex, visited, topoStack, adjacencyList);
        }
    }
    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }
    return topoOrder;
}

int main() {
    int vertices = 6;
    vector<vector<int>> adjacencyList(vertices);
    adjacencyList[5].push_back(2);
    adjacencyList[5].push_back(0);
    adjacencyList[4].push_back(0);
    adjacencyList[4].push_back(1);
    adjacencyList[2].push_back(3);
    adjacencyList[3].push_back(1);
    vector<int> topoOrder = topologicalSortDFS(vertices, adjacencyList);
    for (int vertex : topoOrder) {
        cout << vertex << " ";
    }
    return 0;
}
