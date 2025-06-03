#include <bits/stdc++.h>
using namespace std;

struct HeapNode {
    int value;
    int arrayIndex;
    int elementIndex;
    HeapNode(int v, int ai, int ei) : value(v), arrayIndex(ai), elementIndex(ei) {}
};

struct Compare {
    bool operator()(HeapNode& a, HeapNode& b) {
        return a.value > b.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& lists) {
    priority_queue<HeapNode, vector<HeapNode>, Compare> minHeap;
    for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
            minHeap.push(HeapNode(lists[i][0], i, 0));
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        HeapNode current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);
        int nextIndex = current.elementIndex + 1;
        int arrayIdx = current.arrayIndex;
        if (nextIndex < lists[arrayIdx].size()) {
            minHeap.push(HeapNode(lists[arrayIdx][nextIndex], arrayIdx, nextIndex));
        }
    }
    return result;
}

int main() {
    vector<vector<int>> lists = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {0, 10, 11}
    };
    vector<int> merged = mergeKSortedArrays(lists);
    for (int val : merged) {
        cout << val << " ";
    }
    return 0;
}
