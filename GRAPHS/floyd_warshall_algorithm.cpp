#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void floydWarshall(int numVertices, vector<vector<int>>& distanceMatrix) {
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (distanceMatrix[i][k] < INF && distanceMatrix[k][j] < INF) {
                    distanceMatrix[i][j] = min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }
    }
}

int main() {
    int vertices = 4;
    vector<vector<int>> distanceMatrix(vertices, vector<int>(vertices, INF));
    for (int i = 0; i < vertices; i++) {
        distanceMatrix[i][i] = 0;
    }
    distanceMatrix[0][1] = 5;
    distanceMatrix[0][3] = 10;
    distanceMatrix[1][2] = 3;
    distanceMatrix[2][3] = 1;
    floydWarshall(vertices, distanceMatrix);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (distanceMatrix[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distanceMatrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
