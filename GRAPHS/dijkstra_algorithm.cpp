#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Edge;

vector<int> dijkstraShortestPath(int source, vector<vector<Edge>>& adjacencyList) {
    int numVertices = adjacencyList.size();
    vector<int> distance(numVertices, INT_MAX);
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    distance[source] = 0;
    minHeap.push({0, source});
    while (!minHeap.empty()) {
        int currentDistance = minHeap.top().first;
        int currentVertex = minHeap.top().second;
        minHeap.pop();
        if (currentDistance > distance[currentVertex]) {
            continue;
        }
        for (Edge edge : adjacencyList[currentVertex]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (distance[currentVertex] + weight < distance[neighbor]) {
                distance[neighbor] = distance[currentVertex] + weight;
                minHeap.push({distance[neighbor], neighbor});
            }
        }
    }
    return distance;
}

int main() {
    int vertices = 5;
    vector<vector<Edge>> adjacencyList(vertices);
    auto addEdge = [&](int u, int v, int w) {
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    };
    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);
    vector<int> distances = dijkstraShortestPath(0, adjacencyList);
    for (int i = 0; i < vertices; i++) {
        cout << "Distance to " << i << ": " << distances[i] << "\n";
    }
    return 0;
}
