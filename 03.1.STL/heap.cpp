//
// Created by rituparn on 22.10.23.
//
#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper functions to maintain the heap property
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap() {}

    // Insert an element into the heap
    void insert(int key) {
        heap.push_back(key);

        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove and return the maximum element (root of the max heap)
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1; // or throw an exception
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    // Get the maximum element without removing it
    int getMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1; // or throw an exception
        }
        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(40);
    maxHeap.insert(50);

    std::cout << "Max Element: " << maxHeap.getMax() << std::endl;
    std::cout << "Extracted Max Element: " << maxHeap.extractMax() << std::endl;
    std::cout << "Max Element: " << maxHeap.getMax() << std::endl;

    return 0;
}
