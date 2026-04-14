#include<iostream>
#include<list>
// QUEUE - Fifo 

// FIFO principle
//  Insertion (enqueue) - back
//  Deletion (dequeue)  - front

// Header File
#include <queue>
using namespace std;


//  Operation and Interfaces
// Element Access
        // front() - return reference - first element
        // rear()  - return reference - last element

        // empty() = empty
        // size() - return no. of queue

        // push(const T& val)  - insert element at back
        // emplace(args...) - constructs element in places
        // pop() removes element from front

        // swap(q1 , q2) -  swaps 2 queues
        // relational operators ( == , != )




        //  Default Container
        std::deque<T>
            // Double-ended queue: allows fast insertion / removal from both ends
            // implemented as dynamic array of fixed size blocks

        std::list<T>
            // Doubly linked list.
            // Efficient front/back insert/remove, but worse cache locality.

        // implementation 

    //  Element Access
        // queue.front() - // return a reference first (front) element
        // queue.back()  - // return a reference last (back) element
        // queue.empty() - // true return queue is empty
        // queue.size()  - // Return the number elements queue

        // queue.push(const T& value) - // insert elements back
        // queue.push(T&& value) -  // Insert elements back(move semantics)
        // queue.emplace(args...) - // Constructs elements inplace at the back.
        // queue.pop() - // Remove the front element
 
        // swap(q1 , q2) - // Swaps contents 2 queues 

        

int main() {
    queue<int> q;

    // Modifiers
    q.push(10);
    q.push(20);
    q.emplace(30);

    // Element access
    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30

    // Capacity
    cout << "Size: " << q.size() << endl;   // 3
    cout << "Empty? " << q.empty() << endl; // 0 (false)

    // Pop
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 20

    // Swap
    queue<int> q2;
    q2.push(100);
    swap(q, q2);

    cout << "After swap, q front: " << q.front() << endl;  // 100
    cout << "After swap, q2 front: " << q2.front() << endl; // 20
}
