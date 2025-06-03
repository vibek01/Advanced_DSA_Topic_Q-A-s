#include <bits/stdc++.h>
using namespace std;

bool isBipartiteGraph(int source, vector<int>& color, vector<vector<int>>& adjacencyList) {
    queue<int> vertexQueue;
    color[source] = 1;
    vertexQueue.push(source);
    while (!vertexQueue.empty()) {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();
        for (int neighbor : adjacencyList[currentVertex]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[currentVertex];
                vertexQueue.push(neighbor);
            } else if (color[neighbor] == color[currentVertex]) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<int> color(numVertices, -1);
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (color[vertex] == -1) {
            if (!isBipartiteGraph(vertex, color, adjacencyList)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int vertices = 4;
    vector<vector<int>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    cout << (checkBipartite(vertices, adjacencyList) ? "Bipartite" : "Not Bipartite");
    return 0;
}
