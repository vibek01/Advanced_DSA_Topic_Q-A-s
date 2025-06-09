#include <bits/stdc++.h>
using namespace std;

void threeWayQuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int lt = left;
    int gt = right;
    int i = left;
    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[lt], arr[i]);
            lt++;
            i++;
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[gt]);
            gt--;
        } else {
            i++;
        }
    }
    threeWayQuickSort(arr, left, lt - 1);
    threeWayQuickSort(arr, gt + 1, right);
}

int main() {
    vector<int> arr = {5, 3, 8, 3, 2, 7, 3, 10};
    threeWayQuickSort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
