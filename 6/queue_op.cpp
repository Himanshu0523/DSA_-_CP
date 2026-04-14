#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Prority Queue - (Heap)
    // Special type of queue - based on priority
    // Higher priority elements are dequeued before lower priority elements
    // If two elements have same priority - served according to their order in queue (FIFO)

    // Types of Heaps
        // Max-Heap - parent node >= child nodes
        // Min-Heap - parent node <= child nodes

    // insert - o(log n)
    // remove - o(log n)
    // top - o(1)
    // extract max/min - o(log n)

    //binary Heap is optimal

// Max Priority Queue
//  rules-
    // complete binary tree
    // parent node >= child nodes
    // indexing - 0 based
        // parent(i) = (i-1)/2
        // left child(i) = 2*i + 1
        // right child(i) = 2*i + 2


class PriorityQueue {
    private:
    vector<int> heap;

    void heapifyUp(int idx){
        while(idx > 0) {
            int parent = (idx - 1)/2;
            if(heap[parent] >= heap[idx]) break;
            swap(heap[parent], heap[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx) {
        int n = heap.size();
        while(true){
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if(left < n && heap[left] > heap[largest]) {
                largest = left;
            }
            if(right < n && heap[right] > heap[largest]) {
                largest = right;
            }
            if(largest == idx) break;
            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

    public:
    bool empty(){
        return heap.empty();
    }

    int size(){
        return heap.size();
    }

    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop(){
        if(empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top(){
        if(empty()) return -1;
        return heap[0];
    }
};
    