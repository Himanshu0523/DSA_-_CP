#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// priority_queue

    // queue, which is FIFO, a priority_queue is a max-heap by default → the largest element has the highest priority.
    //  normal queue(FIFO) , element are ordered by priority (largest/smaller depending on comparator)
    //  binary heap internal implemented

    // methods all 
        // top() - 
        // empty() -
        // size() - 
    
        // push(const T& val) -
        // push(T&& val) -
        // emplace(args...) - 
        // pop() - 
    
        // swap() -
    
    
        // internal  Working
        // push() - O(log n) - element is placed in container, heapify min/max heap property
        // pop - top element is removed , heapfiy-down - restore order
        // top() - O(1)
        // size() , empty() - O(1)
        
    // Max-heap (default)
        //   heap - complete binary tree stored in array
        // parent node at time i =>  (i - 1)/2 
        // left child node ar index i => 2* i + 1
        // right child => 2* i + 2



        // push(x) → constructs an object x, then copies/moves it into the container.

        // emplace(args...) → constructs the object in place inside the container.

        // This avoids unnecessary copies → faster and memory efficient
        
        
    // ✔️ Always empty() check before front() / pop().
    // ✔️ Prefer emplace → avoids extra copies.
    // ✔️ Use queue for pure FIFO, deque for FIFO + random access.
    // ✔️ Use swap to clear quickly.
    // ✔️ No iterators → use a temp queue for debugging.
    // ✔️ Pick the right container adapter for the problem.
        
        
    // Why This Matters in CP / Real Projects?
    // C++11: emplace & move → write faster, memory-efficient code.
    // C++17: CTAD → less verbose, cleaner contest code.
    // C++20: constexpr queues → useful in compile-time testing, meta-programming, and guaranteed noexcept swap.


// ***************************************************************

    // Removed custom template declaration to avoid ambiguity with std::priority_queue
    template<
        class T,
        class Container = vector<T>,
        class Compare = less<typename Container::value_type>
    >class priority_queue_;


    
    
    
    int main() {

//         // Underlying Container
                // Default container: std::vector<T>
                // Can be changed to std::deque<T>
                // Cannot use std::list (doesn't support random access)



        //  Default (max-heap)
            priority_queue<int> pq;
        
        //  Min-heap
            priority_queue<int, vector<int> , greater<int>> min_pq;
        
        // With custom comparator
        struct Compare{
            bool operator()(const int& a, const int& b) {
                return a > b; // for min-heap behavior
            }
        };
        priority_queue<int, vector<int>, Compare> custom_pq;
        
    
// Initialization from container
vector<int> vec = {3, 1, 4, 1, 5};
priority_queue<int> pq(vec.begin(), vec.end());


// Member Function 
    // empty()
    bool isEmpty = pq.empty(); // Returns true if empty

    // size()
    size_t count = pq.size(); // Returns number of elements

    // top()
    int topElement = pq.top(); // Returns reference to top element

    // push()
    pq.emplace(10); // Constructs element in-place

    // pop()
    pq.pop(); // Removes top element

    // swap()
    priority_queue<int> other_pq;
    pq.swap(other_pq); // Swaps contents with another priority queue



    return 0;
}
