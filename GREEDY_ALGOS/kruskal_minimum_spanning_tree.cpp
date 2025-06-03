#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DisjointSet {
    vector<int> parent;
    vector<int> rankVec;
    DisjointSet(int n) {
        parent.resize(n);
        rankVec.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findSet(int x) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y) {
        int rx = findSet(x);
        int ry = findSet(y);
        if (rx != ry) {
            if (rankVec[rx] < rankVec[ry]) {
                parent[rx] = ry;
            } else if (rankVec[rx] > rankVec[ry]) {
                parent[ry] = rx;
            } else {
                parent[ry] = rx;
                rankVec[rx]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w < b.w;
    });

    DisjointSet ds(n);
    int totalWeight = 0;

    for (auto& e : edges) {
        if (ds.findSet(e.u) != ds.findSet(e.v)) {
            ds.unionSet(e.u, e.v);
            totalWeight += e.w;
        }
    }

    cout << totalWeight << "\n";
    return 0;
}
