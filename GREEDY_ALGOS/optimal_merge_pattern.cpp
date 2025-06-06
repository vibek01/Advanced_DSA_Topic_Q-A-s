#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<>> minHeap;
    for (int i = 0; i < n; i++) {
        long long size;
        cin >> size;
        minHeap.push(size);
    }

    long long totalCost = 0;
    while (minHeap.size() > 1) {
        long long first = minHeap.top(); minHeap.pop();
        long long second = minHeap.top(); minHeap.pop();
        long long merged = first + second;
        totalCost += merged;
        minHeap.push(merged);
    }

    cout << totalCost << "\n";
    return 0;
}
