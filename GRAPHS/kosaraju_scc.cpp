#include <bits/stdc++.h>
using namespace std;

void dfsFillOrder(int vertex, vector<bool>& visited, stack<int>& orderStack, vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            dfsFillOrder(neighbor, visited, orderStack, adjacencyList);
        }
    }
    orderStack.push(vertex);
}

void dfsOnTranspose(int vertex, vector<bool>& visited, vector<vector<int>>& transposeList, vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : transposeList[vertex]) {
        if (!visited[neighbor]) {
            dfsOnTranspose(neighbor, visited, transposeList, component);
        }
    }
}

vector<vector<int>> kosarajuSCC(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numVertices, false);
    stack<int> orderStack;
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            dfsFillOrder(vertex, visited, orderStack, adjacencyList);
        }
    }
    vector<vector<int>> transposeList(numVertices);
    for (int u = 0; u < numVertices; u++) {
        for (int v : adjacencyList[u]) {
            transposeList[v].push_back(u);
        }
    }
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> stronglyConnectedComponents;
    while (!orderStack.empty()) {
        int currentVertex = orderStack.top();
        orderStack.pop();
        if (!visited[currentVertex]) {
            vector<int> component;
            dfsOnTranspose(currentVertex, visited, transposeList, component);
            stronglyConnectedComponents.push_back(component);
        }
    }
    return stronglyConnectedComponents;
}

int main() {
    int vertices = 5;
    vector<vector<int>> adjacencyList(vertices);
    adjacencyList[1].push_back(0);
    adjacencyList[0].push_back(2);
    adjacencyList[2].push_back(1);
    adjacencyList[0].push_back(3);
    adjacencyList[3].push_back(4);
    vector<vector<int>> scc = kosarajuSCC(vertices, adjacencyList);
    for (auto& component : scc) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << "\n";
    }
    return 0;
}
