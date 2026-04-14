#include <bits/stdc++.h>
using namespace std;


class Deque {
    private:
    int *arr;
    int cap;
    int frontIdx , rearIdx, currSize;

    public:
    Deque(int c){
        cap = c;
        arr = new int[cap];
        frontIdx = -1;
        rearIdx = 0;
        currSize = 0;
    }

    bool empty() {
        return currSize == 0;
    }

    bool full() {
        return currSize == cap;
    }

    void push_front(int x){
        if (full())return ;
        if (empty()) {frontIdx = rearIdx = 0;}
        else { frontIdx = (frontIdx - 1 + cap) % cap;}

        arr[frontIdx] = x;
        currSize++;
    }

    void pop_front() {
        if (empty()) return;
        if (frontIdx == rearIdx) {frontIdx = -1; rearIdx = 0;}
        else {frontIdx = (frontIdx + 1) % cap;}
        currSize--;
    }

    int front() {
        if (empty()) return -1;
        return arr[frontIdx];
    }

    int back() {
        if (empty())return -1;
        return arr[rearIdx];
    }
};