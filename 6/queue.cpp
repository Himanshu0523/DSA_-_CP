#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Queue 
    // FIFO - First In First Out
    // Operations - Enqueue , Dequeue , Front , Rear , isEmpty , size

class Queue {
    private:
    int *arr;
    int cap;
    int frontIdx , rearIdx , currSize;

    public:
    Queue(int capacity) {
        cap = capacity;
        arr = new int[cap];
        frontIdx = 0;
        rearIdx = -1;
        currSize = 0;
    }


    bool isEmpty() {
        return currSize == 0;
    }

    bool full() {
        return currSize == cap;
    }

    int size() {
        return currSize;
    }

    void push(int x){
        if (full())return ;
        rearIdx = (rearIdx + 1) % cap;
        arr[rearIdx] = x;
        currSize++;
    }

    void pop(){
        if(isEmpty()) return ;
        frontIdx = (frontIdx + 1) % cap;
        currSize--;
    }

    int front() {
        if(isEmpty()) return -1;
        return arr[frontIdx];
    }

    int rear() {
        if(isEmpty()) return -1;
        return  arr[rearIdx];
    }

    ~Queue() {
        delete[] arr;
    }
};


int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Rear element: " << q.rear() << endl;   // 30
    cout << "Queue size: " << q.size() << endl;     // 3

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // 20

    return 0;
}

