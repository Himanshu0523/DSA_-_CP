#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
// resize automatically

// Declaration and Initialization
    /*  
        vector<int> v1;                 // empty vector
        vector<int> v2(5);              // size 5, default initialized (0) 
        vector<int> v3(5, 10);          // size 5, all values = 10
        vector<int> v4 = {1 , 2, 3, 4}; // initializer list
        vector<int> v5(v4);                 // copy constructor
    */

// Member Functions
    // Capacity Functions
        /*
            size()           Number of elements
            capacity()       Size of allocated memory (>= size)
            max_size()       Max possible elements
            empty()          returns true if vector is empty
            resize(n)        resizes to n elements
            shrink_to_fit()  Reduces capacity to match size
            reserve(n)       Pre-allocates memory foe at least n elements 
        */
    // Element Access
        /*
            operator[]   Access without bounds check
            at(i)        Access with bounds check
            froont()     first element 
            back()       last element
            data()       pointer to internal array
        */
    // Modifiers
        /*
            push_back()             adds elements at end
            pop_back()              remove last element
            inserrt(pos ,val)       inserts element at position 
            erase(pos)              Erases element at position 
            clear()                 removes all elements
            emplace(pos , ars....)  constructs element in-place
            emplace_back(args....)  in-place construct at end
            assign(count , value)   assign new values
            swap(vec2)              swaps contents with vec2

        */


// Iterators
    /*
        begin()   iterator to first element
        end()     iterator to past-the-ends elements 
        rbegin()  reverse iterator to last
        rend()    reverse iterator to before-first
        cbegin()  const begin
        cend()    const end

    */

// Performance
     /*
        Access[]             O(1)
        push_back()          O(1)
        insert()             O(n)
        erase()              O(n)
        clear()              O(n)     
     */

// Memory Management
    /*
        vector used heap allocation.
        Grows by doubling capacity when needed (amortized cost).
        reserve() can present reallocations if size known in advance.
    */

// Pitfalls and tips
    /*
        Prefer at() fro safety (with bounds check).
        use reserve() when adding amny elelments.
        avoid using vector<bool>  - it's bit packed and not a real vector of bools.
    */ 



/*  Why to Avoid std::vector<bool>
        Bit-packed :- stortes 1 bit , not real bool values 
        No real reference : vb[i] give proxy , not bool&
        No address : &vb[i] - invalid
        Breaks templates - Generic code may not work 
        Debug-unfriendly - Compressed internals haed to inspect

*/

/*
    vector -sequence container that represent dynamic array , 
            Dynamic resizing -   automatically grows and shrinks 
            Random access -      time access - constant by element
            Contiguous storage - elements stored in adjacent memory locations
            Automatic memeory management -  handles allocation & deallocation
*/


void printVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    // in 1D 
        //Empty vector
            vector<int> v0;
        // initialize list
            vector<int> v1 = {1, 2, 3, 4, 5};
        //  (size , default_value)
            vector<int> v2(10);
            vector<int> v3(5, 10);

        // Different data types
            vector<string> names = {"Alice", "Bob", "Charlie"};
            vector<double> prices(10, 0.0);
            vector<bool> flags(8, true);

        // Copy constructor
            vector<int> v4(v1);
        // copy Assignment
            vector<int> v5 = v1;

        // Range constructor
            int arr[] = {10, 20, 30, 40, 50};
            vector<int> v6(arr, arr + 5);


        // Adding elements
            v0.push_back(100);
            
            // insert at specific position (iterator position , value , count, ...)
            v1.insert(v1.begin() + 2, 99); // insert 99 at index 2

    
        // Removing elements
            v1.pop_back(); // remove last element
            v1.erase(v1.begin() + 1); // remove element at index 1
            v2.clear(); // remove all elements

        // Resizing
            v3.resize(8); // resize to 8 elements
            v3.resize(12, 5); // resize to 12 elements, new elements = 5
            v3.shrink_to_fit(); // reduce capacity to fit size
            v3.reserve(20); // reserve space for at least 20 elements

        // Memory allocation
        // size vs capacity
            cout << "Size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;
            v1.push_back(6);
            cout << "After push_back - Size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;


    // modifiers
        // insertion operations
            v1.emplace(v1.begin() + 1, 88); // in-place construct
            v1.emplace_back(77); // in-place at end
            v4.assign(5, 42); // assign 5 elements of value 42

            // range insert (position  ,from iterator , to iterator)
                v1.insert(v1.begin() + 2, v4.begin(), v4.begin() + 3); // range insert


        // Accessing elements
        cout << "First element: " << v1.front() << endl;
        cout << "Last element: " << v1.back() << endl;
        cout << "Element at index 2: " << v1.at(2) << endl;

        // Size and Capacity
        cout << "Size of v1: " << v1.size() << endl;
        cout << "Capacity of v1: " << v1.capacity() << endl;


    // Iterators Types
        vector<int> vec = {1, 2, 3, 4, 5 , 6, 7, 8, 9, 10, 11, 12};

        // Iterating using iterators
            cout << "Elements in vec using iterators: ";
            for (auto it = vec.begin(); it != vec.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;


        // Iterating using reverse iterators
            cout << "Elements in vec using reverse iterators: ";
            for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
                cout << *rit << " ";
            }
            cout << endl;


        // Constant iterators (read-only)
            cout << "Elements in vec using const iterators: ";
            for (auto cit = vec.cbegin(); cit != vec.cend(); ++cit) {
                cout << *cit << " ";
            }
            cout << endl;


        // Iterating using range-based for loop
            cout << "Elements in vec using range-based for loop: ";
            // read-only access
            for (const auto& elem : vec) {
                cout << elem << " ";
            }
            cout << endl;

        // Modify elements  if case reference pass

        // // Remove all even numbers using erase-remove idiom
            vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

        // Reverse iterators
            cout << "Elements in vec using reverse iterators: ";
            for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
                cout << *rit << " ";
            }
            cout << endl;

        
        // Dafault sort (ascending)
        sort(v1.begin(), v1.end());
        
        // Descending sort
        sort(v2.rbegin(),v2.rend());
        // or
        sort(vec.begin(),vec.end() ,greater<int>());


        // Custom comparator
        struct Person {
            string name;
            int age;
        };

        vector<Person> people = {{"Alice" , 25},{"Bob" , 20},{"Chal",30}};

        sort(people.begin(), people.end(), [](const Person& a, const Person& b){return a.age < b.age; });



    // in 2d
    vector<vector<int>> mat(5, vector<int>(5));




    // Even faster with sync disable
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Complier-time
    // constexpr - 


    return 0;
}