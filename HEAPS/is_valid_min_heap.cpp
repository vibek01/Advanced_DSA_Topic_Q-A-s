#include <bits/stdc++.h>
using namespace std;

bool isValidMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n) {
            if (arr[i] > arr[leftChild]) {
                return false;
            }
        }
        if (rightChild < n) {
            if (arr[i] > arr[rightChild]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9, 8};
    vector<int> arr2 = {2, 1, 4, 7, 9};
    cout << isValidMinHeap(arr1) << "\n";
    cout << isValidMinHeap(arr2) << "\n";
    return 0;
}
