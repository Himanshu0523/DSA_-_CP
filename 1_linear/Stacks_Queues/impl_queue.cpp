#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Exception class for empty queue operations
class QueueEmpty : public runtime_error {
public: 
    QueueEmpty(const string& err) : runtime_error(err) { }
};

// Exception class for full queue operations
class QueueFull : public runtime_error {
public: 
    QueueFull(const string& err) : runtime_error(err) { }
};

// ==================== 1. STATIC ARRAY QUEUE (Linear Queue) ====================
template <typename E>
class StaticArrayQueue {
private:
    E* array;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    // Constructor
    StaticArrayQueue(int size = 10) {
        capacity = size;
        array = new E[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    // Destructor
    ~StaticArrayQueue() {
        delete[] array;
    }

    // Returns the number of elements in the queue
    int size() const {
        return currentSize;
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Checks if the queue is full
    bool isFull() const {
        return currentSize == capacity;
    }

    // Returns the front element without removing it
    const E& front() const {
        if (isEmpty()) {
            throw QueueEmpty("Queue is empty");
        }
        return array[frontIndex];
    }

    // Adds an element to the rear of the queue
    void enqueue(const E& e) {
        if (isFull()) {
            throw QueueFull("Queue is full");
        }
        
        rearIndex++;
        array[rearIndex] = e;
        currentSize++;
    }

    // Removes the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw QueueEmpty("Cannot dequeue from empty queue");
        }
        
        frontIndex++;
        currentSize--;
        
        // If queue becomes empty, reset indices
        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    // Display queue contents
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Static Queue (front to rear): ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// ==================== 2. CIRCULAR ARRAY QUEUE ====================
template <typename E>
class CircularArrayQueue {
private:
    E* array;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    // Constructor
    CircularArrayQueue(int size = 10) {
        capacity = size;
        array = new E[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    // Destructor
    ~CircularArrayQueue() {
        delete[] array;
    }

    // Returns the number of elements in the queue
    int size() const {
        return currentSize;
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Checks if the queue is full
    bool isFull() const {
        return currentSize == capacity;
    }

    // Returns the front element without removing it
    const E& front() const {
        if (isEmpty()) {
            throw QueueEmpty("Queue is empty");
        }
        return array[frontIndex];
    }

    // Adds an element to the rear of the queue using modulo arithmetic
    void enqueue(const E& e) {
        if (isFull()) {
            throw QueueFull("Queue is full");
        }
        
        rearIndex = (rearIndex + 1) % capacity;
        array[rearIndex] = e;
        currentSize++;
    }

    // Removes the front element from the queue using modulo arithmetic
    void dequeue() {
        if (isEmpty()) {
            throw QueueEmpty("Cannot dequeue from empty queue");
        }
        
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        
        // Reset indices if queue becomes empty
        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    // Display queue contents (handles circular nature)
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Circular Queue (front to rear): ";
        if (frontIndex <= rearIndex) {
            // Normal case: front before rear
            for (int i = frontIndex; i <= rearIndex; i++) {
                cout << array[i] << " ";
            }
        } else {
            // Wrapped case: rear before front
            for (int i = frontIndex; i < capacity; i++) {
                cout << array[i] << " ";
            }
            for (int i = 0; i <= rearIndex; i++) {
                cout << array[i] << " ";
            }
        }
        cout << endl;
    }
};

// ==================== 3. LINKED LIST QUEUE ====================
template <typename E>
class LinkedListQueue {
private:
    // Node structure
    struct Node {
        E data;
        Node* next;
        Node(const E& value) : data(value), next(nullptr) {}
    };
    
    Node* frontNode;
    Node* rearNode;
    int currentSize;

public:
    // Constructor
    LinkedListQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
        currentSize = 0;
    }

    // Destructor
    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Copy constructor
    LinkedListQueue(const LinkedListQueue& other) {
        frontNode = nullptr;
        rearNode = nullptr;
        currentSize = 0;
        
        // Copy all elements from other queue
        Node* temp = other.frontNode;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }

    // Assignment operator
    LinkedListQueue& operator=(const LinkedListQueue& other) {
        if (this != &other) {
            // Clear current queue
            while (!isEmpty()) {
                dequeue();
            }
            
            // Copy all elements from other queue
            Node* temp = other.frontNode;
            while (temp != nullptr) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    // Returns the number of elements in the queue
    int size() const {
        return currentSize;
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Linked list queue never gets full (until memory exhaustion)
    bool isFull() const {
        return false;
    }

    // Returns the front element without removing it
    const E& front() const {
        if (isEmpty()) {
            throw QueueEmpty("Queue is empty");
        }
        return frontNode->data;
    }

    // Adds an element to the rear of the queue
    void enqueue(const E& e) {
        Node* newNode = new Node(e);
        
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        currentSize++;
    }

    // Removes the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw QueueEmpty("Cannot dequeue from empty queue");
        }
        
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        currentSize--;
        
        if (isEmpty()) {
            rearNode = nullptr;
        }
    }

    // Display queue contents
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Linked List Queue (front to rear): ";
        Node* temp = frontNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ==================== DEMONSTRATION ====================
int main() {
    cout << "=== QUEUE IMPLEMENTATIONS COMPARISON ===" << endl << endl;

    cout << "1. STATIC ARRAY QUEUE (with wasted space):" << endl;
    StaticArrayQueue<int> staticQueue(3);
    staticQueue.enqueue(10);
    staticQueue.enqueue(20);
    staticQueue.enqueue(30);
    staticQueue.display();
    
    staticQueue.dequeue();
    staticQueue.display();
    cout << "Wasted space visible - cannot reuse empty slots" << endl << endl;

    cout << "2. CIRCULAR ARRAY QUEUE (no wasted space):" << endl;
    CircularArrayQueue<int> circularQueue(3);
    circularQueue.enqueue(10);
    circularQueue.enqueue(20);
    circularQueue.enqueue(30);
    circularQueue.display();
    
    circularQueue.dequeue();
    circularQueue.enqueue(40); // Reuses the freed space
    circularQueue.display();
    cout << "No wasted space - circular reuse of array" << endl << endl;

    cout << "3. LINKED LIST QUEUE (dynamic size):" << endl;
    LinkedListQueue<int> linkedQueue;
    linkedQueue.enqueue(10);
    linkedQueue.enqueue(20);
    linkedQueue.enqueue(30);
    linkedQueue.display();
    
    linkedQueue.dequeue();
    linkedQueue.enqueue(40);
    linkedQueue.enqueue(50);
    linkedQueue.enqueue(60); // Can keep growing
    linkedQueue.display();
    cout << "Dynamic size - no fixed capacity limit" << endl << endl;

    // Test edge cases
    cout << "=== EDGE CASE TESTING ===" << endl;
    
    // Test empty queue operations
    try {
        LinkedListQueue<int> emptyQueue;
        emptyQueue.dequeue();
    } catch (const QueueEmpty& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    // Test full queue operations
    try {
        CircularArrayQueue<int> fullQueue(2);
        fullQueue.enqueue(1);
        fullQueue.enqueue(2);
        fullQueue.enqueue(3); // Should throw
    } catch (const QueueFull& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    return 0;
}