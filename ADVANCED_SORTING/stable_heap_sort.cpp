#include <bits/stdc++.h>
using namespace std;

void heapify(vector<pair<int,int>>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && (arr[left].first < arr[smallest].first ||
        (arr[left].first == arr[smallest].first && arr[left].second < arr[smallest].second))) {
        smallest = left;
    }
    if (right < n && (arr[right].first < arr[smallest].first ||
        (arr[right].first == arr[smallest].first && arr[right].second < arr[smallest].second))) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void stableHeapSort(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int,int>> heapArr(n);
    for (int i = 0; i < n; i++) {
        heapArr[i] = {arr[i], i};
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heapArr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(heapArr[0], heapArr[i]);
        heapify(heapArr, i, 0);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = heapArr[n - 1 - i].first;
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
    stableHeapSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
