#include <bits/stdc++.h>
using namespace std;

vector<int> findKLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> arr = {3, 1, 5, 12, 2, 11, 6};
    int k = 3;
    vector<int> largest = findKLargest(arr, k);
    for (int val : largest) {
        cout << val << " ";
    }
    return 0;
}
