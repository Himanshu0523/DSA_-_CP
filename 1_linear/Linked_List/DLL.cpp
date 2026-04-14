#include <iostream>
#include <stdexcept>

using namespace std;

typedef string Elem;

class DNode
{
private:
    Elem elem;
    DNode *prev;
    DNode *next;
    friend class DLinkedList;
};

class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem &front() const;
    const Elem &back() const;
    void addFront(const Elem &e);
    void addBack(const Elem &e);
    void removeFront();
    void removeBack();
    void displayForward() const;
    void displayBackward() const;
    int size() const;

private:
    DNode *header;
    DNode *trailer;

protected:
    void add(DNode *v, const Elem &e);
    void remove(DNode *v);
};

DLinkedList::DLinkedList()
{
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
}

DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const
{
    return header->next == trailer;
}

const Elem &DLinkedList::front() const
{
    if (empty())
        throw runtime_error("List is empty");
    return header->next->elem;
}

const Elem &DLinkedList::back() const
{
    if (empty())
        throw runtime_error("List is empty");
    return header->next->elem;
}

void DLinkedList ::add(DNode *v, const Elem &e)
{
    DNode *newNode = new DNode;
    newNode->elem = e;

    newNode->next = v;
    newNode->prev = v->prev;
    v->prev->next = newNode;
    v->prev = newNode;
}

void DLinkedList ::addFront(const Elem &e)
{
    add(header->next, e);
}

void DLinkedList ::addBack(const Elem &e)
{
    add(trailer, e);
}

void DLinkedList ::remove(DNode *v)
{
    if (empty())
        throw runtime_error("List is empty");

    DNode *u = v->prev;
    DNode *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()
{
    remove(header->next);
}

void DLinkedList::removeBack()
{
    remove(trailer->prev);
}

void DLinkedList::displayForward() const
{
    if (empty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *current = header->next;
    cout << "Forward:  ";

    while (current != trailer)
    {
        cout << current->elem;
        if (current->next != trailer)
            cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}

void DLinkedList::displayBackward() const
{
    if (empty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *current = trailer->prev;
    cout << "Backward: ";
    while (current != header)
    {
        cout << current->elem;
        if (current->prev != header)
            cout << " <-> ";
        current = current->prev;
    }
    cout << endl;
}

int DLinkedList::size() const
{
    int count = 0;
    DNode *current = header->next;
    while (current != trailer)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{

    DLinkedList list;
    
    // Test the doubly linked list
    cout << "Creating a doubly linked list..." << endl;
    
    // Add elements to front and back
    list.addFront("Apple");
    list.addBack("Banana");
    list.addFront("Cherry");
    list.addBack("Date");
    
    // Display the list
    list.displayForward();
    list.displayBackward();
    cout << "Size: " << list.size() << endl;
    
    // Access front and back elements
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    
    // Remove elements
    list.removeFront();
    cout << "After removing front: ";
    list.displayForward();
    
    list.removeBack();
    cout << "After removing back: ";
    list.displayForward();
    
    // Check if empty
    cout << "Is empty? " << (list.empty() ? "Yes" : "No") << endl;
    
    // Remove remaining elements
    list.removeFront();
    list.removeBack();
    
    cout << "After removing all elements: ";
    list.displayForward();
    cout << "Is empty? " << (list.empty() ? "Yes" : "No") << endl;

    return 0;
}