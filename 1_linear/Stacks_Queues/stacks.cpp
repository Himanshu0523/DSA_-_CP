#include <iostream>
#include <stdexcept>

using namespace std;

// Stacks - LIFO - last in first out

// Fixed Exception Class Inheritance :-
class StackEmpty : public runtime_error {
    public:
    StackEmpty(const string& err) : runtime_error(err) {}
};

class StackFull : public runtime_error {
    public:
    StackFull(const string& err) : runtime_error(err) {}
};
// runtime_error , 


// Stack Interface
template <typename E>
class Stack {
    public:
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual const E& top() const throw(StackEmpty) = 0;
        virtual void push(const E& e) throw(StackFull) = 0;
        virtual void pop() throw(StackEmpty) = 0;
        virtual ~Stack() {}
};


// ArrayStack implementation
template <typename E>
class ArrayStack : public Stack<E> {
        enum { DEF_CAPACITY = 100};

    public:
    // Constructor
        ArrayStack (int cap = DEF_CAPACITY);

    // Copy Constructor
        ArrayStack (const ArrayStack& other);

    // Assignment operator
        ArrayStack& operator=(const ArrayStack& other );

    // Destructor
        ~ArrayStack();

    // Stack operations
        int size() const;
        bool empty() const;
        const E& top() const throw(StackEmpty);
        void push(const E& e)throw(StackFull);
        void pop() throw (StackEmpty);
        
    // utility methods
        int capacity( )const {return capacity_;}
        void clear() { t = -1;}

    private:
        E* S;
        int capacity_;
        int t;
};

// constructor
template <typename E> 
ArrayStack<E> :: ArrayStack(int cap) : capacity_(cap), t(-1){
    S = new E[capacity_];
}

// Copy Constructor
template <typename E>
ArrayStack <E> :: ArrayStack(const ArrayStack& other) : capacity_(other.capacity_) ,t(other.t){
    S = new E[capacity_];
    for(int i = 0; i<= t; i++) {
        S[i] = other.S[i];
    }
}

// Assigment Operator
template <typename E>
ArrayStack<E>& ArrayStack<E> :: operator=(const ArrayStack& other) {
    if(this != &other) {
        delete[] S;

        capacity_ = other.capacity_;
        t = other.t;
        S = new E[capacity_];
        for(int i = 0; i<= t; i++) {
            S[i] = other.S[i];
        }
    }
    return *this;
}

// Destructor
template <typename E>
ArrayStack<E> :: ~ArrayStack() {
    delete[] S;
}

template <typename E> 
int ArrayStack<E> :: size() const {return (t+1);}

template <typename E> 
bool ArrayStack<E> :: empty() const { return (t < 0);}

template <typename E> 
const E& ArrayStack<E> :: top() const throw(StackEmpty) {
    if(empty()) throw StackEmpty("Top of empty stack");
    return S[t];
}

template <typename E>
void ArrayStack<E> :: push(const E& e) throw(StackFull) {
    if(size() == capacity_) throw StackFull("Push to full stack");
    S[++t] = e;
}

template <typename E>
void ArrayStack<E> :: pop() throw(StackEmpty) {
    if (empty()) throw StackEmpty("Pop from empty stack");
    --t;
}


int main() {
    try {
        ArrayStack<int> st(3);
        st.push(10);
        st.push(20);
        cout << "Top: " << st.top() << endl;
        st.pop();
        cout << "Top after pop: " << st.top() << endl;
    }
    catch (runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
}