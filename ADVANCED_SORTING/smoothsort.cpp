#include <bits/stdc++.h>
using namespace std;

void siftDown(vector<int>& arr, int start, int size) {
    int root = start;
    while (2 * root + 1 < size) {
        int child = 2 * root + 1;
        int swapIdx = root;
        if (arr[swapIdx] < arr[child]) {
            swapIdx = child;
        }
        if (child + 1 < size && arr[swapIdx] < arr[child + 1]) {
            swapIdx = child + 1;
        }
        if (swapIdx == root) {
            return;
        } else {
            swap(arr[root], arr[swapIdx]);
            root = swapIdx;
        }
    }
}

void heapify(vector<int>& arr) {
    int size = arr.size();
    for (int start = size / 2 - 1; start >= 0; start--) {
        siftDown(arr, start, size);
    }
}

void smoothSort(vector<int>& arr) {
    int n = arr.size();
    heapify(arr);
    for (int end = n - 1; end > 0; end--) {
        swap(arr[0], arr[end]);
        siftDown(arr, 0, end);
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
    smoothSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
