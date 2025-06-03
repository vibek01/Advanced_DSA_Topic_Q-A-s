#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
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
public:
    void insertKey(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }
    int extractMax() {
        if (heap.empty()) {
            return INT_MIN;
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }
    int getSize() {
        return heap.size();
    }
};

int main() {
    MaxHeap maxHeap;
    vector<int> values = {3, 10, 5, 1, 8, 7};
    for (int val : values) {
        maxHeap.insertKey(val);
    }
    while (maxHeap.getSize() > 0) {
        cout << maxHeap.extractMax() << " ";
    }
    return 0;
}
