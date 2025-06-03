#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void heapSort(vector<int>& arr, int left, int right) {
    priority_queue<int> pq;
    for (int i = left; i <= right; i++) {
        pq.push(arr[i]);
    }
    for (int i = right; i >= left; i--) {
        arr[i] = pq.top();
        pq.pop();
    }
}

void introsortUtil(vector<int>& arr, int left, int right, int depthLimit) {
    int size = right - left + 1;
    if (size <= 16) {
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }
    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }
    int pivot = arr[left + size / 2];
    int partitionIndex = partition(arr, left, right, pivot);
    introsortUtil(arr, left, partitionIndex - 1, depthLimit - 1);
    introsortUtil(arr, partitionIndex, right, depthLimit - 1);
}

void introSort(vector<int>& arr) {
    int depthLimit = 2 * log(arr.size());
    introsortUtil(arr, 0, arr.size() - 1, depthLimit);
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
    introSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
