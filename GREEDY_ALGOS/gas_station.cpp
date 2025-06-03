#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int start = 0;
    int totalSurplus = 0;
    int currentSurplus = 0;

    for (int i = 0; i < n; i++) {
        currentSurplus += gas[i] - cost[i];
        totalSurplus += gas[i] - cost[i];
        if (currentSurplus < 0) {
            start = i + 1;
            currentSurplus = 0;
        }
    }

    if (totalSurplus >= 0) {
        cout << start << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
