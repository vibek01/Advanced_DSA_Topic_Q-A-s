#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int>& heap, int index, int size) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void buildMaxHeap(vector<int>& heap) {
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, i, size);
    }
}

int main() {
    vector<int> heap = {5, 3, 8, 4, 1, 2, 7};
    buildMaxHeap(heap);
    for (int val : heap) {
        cout << val << " ";
    }
    return 0;
}
