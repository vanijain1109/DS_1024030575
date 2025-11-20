#include <iostream>
using namespace std;
class MaxHeap {
private:
    int *arr;
    int capacity;
    int size;
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (arr[parent] < arr[idx]) {
                int t = arr[parent]; arr[parent] = arr[idx]; arr[idx] = t;
                idx = parent;
            } else break;
        }
    }
    void heapifyDown(int idx) {
        while (2*idx + 1 < size) {
            int l = 2*idx + 1;
            int r = 2*idx + 2;
            int largest = idx;
            if (l < size && arr[l] > arr[largest]) largest = l;
            if (r < size && arr[r] > arr[largest]) largest = r;
            if (largest != idx) {
                int t = arr[largest]; arr[largest] = arr[idx]; arr[idx] = t;
                idx = largest;
            } else break;
        }
    }
public:
    MaxHeap(int cap=100) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    ~MaxHeap() { 
        delete[] arr; 
    }
    void insert(int x) {
        if (size == capacity) {
            cout << "Heap full\n"; return;
        }
        arr[size] = x;
        heapifyUp(size);
        size++;
    }
    int top() {
        if (size == 0) 
        return -1; 
        return arr[0];
    }
    int extractMax() {
        if (size == 0) return -1;
        int ret = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapifyDown(0);
        return ret;
    }

    bool empty() { return size == 0; }
};
int main() {
    MaxHeap pq(50);
    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(50);
    cout << "Top: " << pq.top() << "\n";
    while (!pq.empty()) {
        cout << "Pop: " << pq.extractMax() << "\n";
    }
    return 0;
}
