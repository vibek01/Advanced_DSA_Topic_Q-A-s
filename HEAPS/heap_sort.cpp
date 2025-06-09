#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int>& arr, int index, int size) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < size && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }
        
        if (rightChild < size && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void buildMaxHeap(vector<int>& arr) {
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, i, size);
    }
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    int size = arr.size();
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyDown(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}
