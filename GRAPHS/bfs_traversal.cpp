#include <bits/stdc++.h>
using namespace std;

void breadthFirstSearch(int startVertex, vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();
    vector<bool> visited(numVertices, false);
    queue<int> vertexQueue;
    visited[startVertex] = true;
    vertexQueue.push(startVertex);
    while (!vertexQueue.empty()) {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();
        cout << currentVertex << " ";
        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                vertexQueue.push(neighbor);
            }
        }
    }
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
    breadthFirstSearch(0, adjacencyList);
    return 0;
}
