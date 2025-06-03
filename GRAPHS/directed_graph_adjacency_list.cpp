#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
    }

    void printGraph() {
        for (int vertex = 0; vertex < numVertices; vertex++) {
            cout << vertex << ": ";
            for (int neighbor : adjacencyList[vertex]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int vertices = 5;
    Graph graph(vertices);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.printGraph();
    return 0;
}
