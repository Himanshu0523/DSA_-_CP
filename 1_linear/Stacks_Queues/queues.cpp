#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Exception class -  empty queue operations
class QueueEmpty : public runtime_error {
public: 
    QueueEmpty(const string& err) : runtime_error(err) { }
};

// Exception class -  full queue operations
class QueueFull : public runtime_error {
public: 
    QueueFull(const string& err) : runtime_error(err) { }
};

template <typename E>
class Queue {
private:
    E* array;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;
    bool fixedSize; 

    
    void resize() {
        if (fixedSize) {
            throw QueueFull("Queue is full and has fixed size");
        }
        
        int newCapacity = capacity * 2;
        E* newArray = new E[newCapacity];
        
        // Copy elements from old array to new array
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[(frontIndex + i) % capacity];
        }
        
        delete[] array;
        array = newArray;
        capacity = newCapacity;
        frontIndex = 0;
        rearIndex = currentSize;
    }

public:
    // Constructor - dynamic by default
    Queue(int initialCapacity = 10, bool isFixedSize = false) {
        capacity = initialCapacity;
        array = new E[capacity];
        frontIndex = 0;
        rearIndex = 0;
        currentSize = 0;
        fixedSize = isFixedSize;
    }

    // Destructor
    ~Queue() {
        delete[] array;
    }

    // Copy constructor
    Queue(const Queue& other) {
        capacity = other.capacity;
        currentSize = other.currentSize;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        fixedSize = other.fixedSize;
        
        array = new E[capacity];
        for (int i = 0; i < capacity; i++) {
            array[i] = other.array[i];
        }
    }

    // Assignment operator
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] array;
            
            capacity = other.capacity;
            currentSize = other.currentSize;
            frontIndex = other.frontIndex;
            rearIndex = other.rearIndex;
            fixedSize = other.fixedSize;
            
            array = new E[capacity];
            for (int i = 0; i < capacity; i++) {
                array[i] = other.array[i];
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

    // Checks if the queue is full (useful for fixed-size queues)
    bool isFull() const {
        return currentSize == capacity;
    }

    // Legacy empty method (for compatibility)
    bool empty() const {
        return isEmpty();
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
            if (fixedSize) {
                throw QueueFull("Queue is full");
            } else {
                resize();
            }
        }
        
        array[rearIndex] = e;
        rearIndex = (rearIndex + 1) % capacity;
        currentSize++;
    }

    // Removes the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw QueueEmpty("Cannot dequeue from empty queue");
        }
        
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    // Additional utility function to display queue contents
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue contents (front to rear): ";
        for (int i = 0; i < currentSize; i++) {
            int index = (frontIndex + i) % capacity;
            cout << array[index] << " ";
        }
        cout << endl;
    }

    // Get the maximum capacity of the queue
    int getCapacity() const {
        return capacity;
    }

    // Check if queue has fixed size
    bool isFixedSize() const {
        return fixedSize;
    }
};

// Example usage
int main() {
    cout << "=== Dynamic Queue Example ===" << endl;
    Queue<int> dynamicQueue(3); // Small capacity for testing
    
    // Test dynamic queue
    dynamicQueue.enqueue(10);
    dynamicQueue.enqueue(20);
    dynamicQueue.enqueue(30);
    cout << "Dynamic queue size: " << dynamicQueue.size() << endl;
    cout << "Is dynamic queue full? " << (dynamicQueue.isFull() ? "Yes" : "No") << endl;
    cout << "Is dynamic queue empty? " << (dynamicQueue.isEmpty() ? "Yes" : "No") << endl;
    dynamicQueue.display();
    
    // Test auto-resizing
    dynamicQueue.enqueue(40); // This should trigger resize
    cout << "After adding 4th element:" << endl;
    cout << "New capacity: " << dynamicQueue.getCapacity() << endl;
    dynamicQueue.display();
    
    cout << "\n=== Fixed Size Queue Example ===" << endl;
    Queue<int> fixedQueue(3, true); // Fixed size queue
    
    fixedQueue.enqueue(100);
    fixedQueue.enqueue(200);
    fixedQueue.enqueue(300);
    cout << "Fixed queue size: " << fixedQueue.size() << endl;
    cout << "Is fixed queue full? " << (fixedQueue.isFull() ? "Yes" : "No") << endl;
    fixedQueue.display();
    
    // Test fixed queue full exception
    try {
        fixedQueue.enqueue(400); // This should throw exception
    } catch (const QueueFull& e) {
        cout << "Caught QueueFull exception: " << e.what() << endl;
    }
    
    // Test empty checks
    while (!fixedQueue.isEmpty()) {
        fixedQueue.dequeue();
    }
    cout << "After dequeuing all elements, is empty? " << (fixedQueue.isEmpty() ? "Yes" : "No") << endl;
    
    // Test empty exception
    try {
        fixedQueue.dequeue();
    } catch (const QueueEmpty& e) {
        cout << "Caught QueueEmpty exception: " << e.what() << endl;
    }
    
    return 0;
}