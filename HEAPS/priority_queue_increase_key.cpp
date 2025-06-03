#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<pair<int,int>> heap;
    unordered_map<int,int> indexMap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index].first > heap[parentIndex].first) {
                swap(heap[index], heap[parentIndex]);
                indexMap[heap[index].second] = index;
                indexMap[heap[parentIndex].second] = parentIndex;
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
            if (leftChild < size && heap[leftChild].first > heap[largest].first) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild].first > heap[largest].first) {
                largest = rightChild;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                indexMap[heap[index].second] = index;
                indexMap[heap[largest].second] = largest;
                index = largest;
            } else {
                break;
            }
        }
    }
public:
    void insert(int key, int id) {
        heap.push_back({key, id});
        int index = heap.size() - 1;
        indexMap[id] = index;
        heapifyUp(index);
    }
    void increaseKey(int id, int newKey) {
        int index = indexMap[id];
        heap[index].first = newKey;
        heapifyUp(index);
    }
    pair<int,int> extractMax() {
        if (heap.empty()) {
            return {INT_MIN, -1};
        }
        pair<int,int> maxVal = heap[0];
        indexMap.erase(maxVal.second);
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            indexMap[heap[0].second] = 0;
            heapifyDown(0);
        }
        return maxVal;
    }
    int getSize() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 1);
    pq.insert(5, 2);
    pq.insert(8, 3);
    pq.increaseKey(2, 12);
    while (pq.getSize() > 0) {
        pair<int,int> top = pq.extractMax();
        cout << "(" << top.first << "," << top.second << ") ";
    }
    return 0;
}
