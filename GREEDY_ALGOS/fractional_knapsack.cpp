#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double,pair<int,int>>> items(n);
    int capacity;
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        items[i] = { double(value) / weight, {weight, value} };
    }
    cin >> capacity;

    sort(items.begin(), items.end(), greater<>());

    double totalValue = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        int weight = items[i].second.first;
        int value = items[i].second.second;
        if (weight <= capacity) {
            capacity -= weight;
            totalValue += value;
        } else {
            totalValue += items[i].first * capacity;
            capacity = 0;
        }
    }

    cout << fixed << setprecision(2) << totalValue << "\n";
    return 0;
}
