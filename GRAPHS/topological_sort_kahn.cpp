#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSortKahn(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<int> inDegree(numVertices, 0);
    for (int vertex = 0; vertex < numVertices; vertex++) {
        for (int neighbor : adjacencyList[vertex]) {
            inDegree[neighbor]++;
        }
    }
    queue<int> zeroInDegreeQueue;
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (inDegree[vertex] == 0) {
            zeroInDegreeQueue.push(vertex);
        }
    }
    vector<int> topoOrder;
    while (!zeroInDegreeQueue.empty()) {
        int currentVertex = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        topoOrder.push_back(currentVertex);
        for (int neighbor : adjacencyList[currentVertex]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                zeroInDegreeQueue.push(neighbor);
            }
        }
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
    vector<int> topoOrder = topologicalSortKahn(vertices, adjacencyList);
    for (int vertex : topoOrder) {
        cout << vertex << " ";
    }
    return 0;
}
