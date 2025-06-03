#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;
            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }
public:
    void insertKey(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }
    int extractMin() {
        if (heap.empty()) {
            return INT_MAX;
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }
    int getSize() {
        return heap.size();
    }
};

int main() {
    MinHeap minHeap;
    vector<int> values = {4, 2, 9, 1, 6, 7};
    for (int val : values) {
        minHeap.insertKey(val);
    }
    while (minHeap.getSize() > 0) {
        cout << minHeap.extractMin() << " ";
    }
    return 0;
}
