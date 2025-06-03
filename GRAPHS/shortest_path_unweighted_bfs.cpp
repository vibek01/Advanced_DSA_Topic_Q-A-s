#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathUnweighted(int source, vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();
    vector<int> distance(numVertices, -1);
    queue<int> vertexQueue;
    distance[source] = 0;
    vertexQueue.push(source);
    while (!vertexQueue.empty()) {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();
        for (int neighbor : adjacencyList[currentVertex]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[currentVertex] + 1;
                vertexQueue.push(neighbor);
            }
        }
    }
    return distance;
}

int main() {
    int vertices = 7;
    vector<vector<int>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    vector<int> distances = shortestPathUnweighted(0, adjacencyList);
    for (int i = 0; i < vertices; i++) {
        cout << "Distance to " << i << ": " << distances[i] << "\n";
    }
    return 0;
}
