#include <bits/stdc++.h>
using namespace std;

void inPlaceMerge(vector<int>& arr, int left, int mid, int right) {
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) return;
    while (left <= mid && start2 <= right) {
        if (arr[left] <= arr[start2]) {
            left++;
        } else {
            int value = arr[start2];
            int index = start2;
            while (index != left) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[left] = value;
            left++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        inPlaceMerge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
