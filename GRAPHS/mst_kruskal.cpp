#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u;
    int v;
    int weight;
};

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] != vertex) {
        parent[vertex] = findParent(parent[vertex], parent);
    }
    return parent[vertex];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rankVec) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    if (rankVec[parentU] < rankVec[parentV]) {
        parent[parentU] = parentV;
    } else if (rankVec[parentU] > rankVec[parentV]) {
        parent[parentV] = parentU;
    } else {
        parent[parentV] = parentU;
        rankVec[parentU]++;
    }
}

vector<Edge> kruskalMST(int numVertices, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight < b.weight;
    });
    vector<int> parent(numVertices);
    vector<int> rankVec(numVertices, 0);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }
    vector<Edge> mstEdges;
    for (Edge edge : edges) {
        int parentU = findParent(edge.u, parent);
        int parentV = findParent(edge.v, parent);
        if (parentU != parentV) {
            mstEdges.push_back(edge);
            unionSets(parentU, parentV, parent, rankVec);
        }
    }
    return mstEdges;
}

int main() {
    int vertices = 6;
    vector<Edge> edges;
    edges.push_back({0, 1, 4});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 2});
    edges.push_back({1, 0, 4});
    edges.push_back({2, 0, 4});
    edges.push_back({2, 1, 2});
    edges.push_back({2, 3, 3});
    edges.push_back({2, 5, 2});
    edges.push_back({2, 4, 4});
    edges.push_back({3, 2, 3});
    edges.push_back({3, 4, 3});
    edges.push_back({4, 2, 4});
    edges.push_back({4, 3, 3});
    edges.push_back({5, 2, 2});
    edges.push_back({5, 4, 3});
    vector<Edge> mst = kruskalMST(vertices, edges);
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " (" << e.weight << ")\n";
    }
    return 0;
}
