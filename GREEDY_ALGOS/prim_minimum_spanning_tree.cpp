#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n);
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        inMST[u] = true;
        for (auto& p : adj[u]) {
            int v = p.first;
            int weight = p.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
            }
        }
    }

    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        totalWeight += key[i];
    }

    cout << totalWeight << "\n";
    return 0;
}
