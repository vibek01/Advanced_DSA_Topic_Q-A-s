#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Edge;

vector<Edge> primMST(int numVertices, vector<vector<Edge>>& adjacencyList) {
    vector<bool> inMST(numVertices, false);
    vector<int> key(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    key[0] = 0;
    minHeap.push({0, 0});
    while (!minHeap.empty()) {
        int currentVertex = minHeap.top().second;
        minHeap.pop();
        if (inMST[currentVertex]) {
            continue;
        }
        inMST[currentVertex] = true;
        for (Edge edge : adjacencyList[currentVertex]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (!inMST[neighbor] && weight < key[neighbor]) {
                key[neighbor] = weight;
                parent[neighbor] = currentVertex;
                minHeap.push({key[neighbor], neighbor});
            }
        }
    }
    vector<Edge> mstEdges;
    for (int vertex = 1; vertex < numVertices; vertex++) {
        mstEdges.push_back({parent[vertex], vertex});
    }
    return mstEdges;
}

int main() {
    int vertices = 5;
    vector<vector<Edge>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v, int w) {
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    };
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);
    vector<Edge> mst = primMST(vertices, adjacencyList);
    for (Edge e : mst) {
        cout << e.first << " - " << e.second << "\n";
    }
    return 0;
}
