#include <iostream>
#include <stdexcept>

using namespace std;

typedef string Elem;

class CNode
{
private:
    Elem elem;
    CNode *next;

    friend class CircleList;
};

class CircleList
{
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem &front() const;
    const Elem &back() const;
    void advance();
    void add(const Elem &e);
    void remove();
    void display() const;
    int size() const;

private:
    CNode *cursor;
};

CircleList::CircleList() : cursor(NULL)
{
}

CircleList::~CircleList()
{
    while (!empty())
        remove();
}

bool CircleList::empty() const { return cursor == NULL; }

const Elem &CircleList::back() const
{
    if (empty())
        throw runtime_error("List is empty");
    return cursor->elem;
}

const Elem &CircleList::front() const
{
    if (empty())
        throw runtime_error("List is empty");
    return cursor->next->elem;
}

void CircleList ::advance()
{
    if (!empty())
        cursor = cursor->next;
}

void CircleList ::add(const Elem &e)
{
    CNode *v = new CNode;
    v->elem = e;
    if (cursor == nullptr)
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList ::remove()
{
    if (empty())
        throw runtime_error("Cannot remove from empty list");

    CNode *old = cursor->next;
    if (old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;
    delete old;
}

void CircleList::display() const
{
    if (empty())
    {
        cout << "List is empty" << endl;
        return;
    }

    CNode *current = cursor->next;
    cout << "Circular List: ";

    do
    {
        cout << current->elem;
        current = current->next;
        if (current != cursor->next)
            cout << " -> ";
    } while (current != cursor->next);

    cout << " (back to front) " << endl;
}

int CircleList::size() const
{
    if (empty())
        return 0;

    int count = 0;
    CNode *current = cursor->next;
    do
    {
        count++;
        current = current->next;
    } while (current != cursor->next);

    return count;
}

int main()
{
    CircleList list;

    cout << "Creating a circular linked list..." << endl;

    // Test adding elements
    list.add("Apple");
    list.add("Banana");
    list.add("Cherry");
    list.add("Date");

    // Display the list
    list.display();
    cout << "Size: " << list.size() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    // Test advancing
    cout << "\nAdvancing cursor..." << endl;
    list.advance();
    list.display();
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    // Test removing
    cout << "\nRemoving front element..." << endl;
    list.remove();
    list.display();
    cout << "Size: " << list.size() << endl;

    // Test multiple advances
    cout << "\nAdvancing twice..." << endl;
    list.advance();
    list.advance();
    list.display();

    // Test removing all elements
    cout << "\nRemoving all elements..." << endl;
    while (!list.empty())
    {
        list.remove();
    }
    list.display();
    cout << "Is empty? " << (list.empty() ? "Yes" : "No") << endl;

    return 0;
}