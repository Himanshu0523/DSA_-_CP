#include<iostream>
#include<deque>
using namespace std;

#define x 12


/*
    std::deque (Double Ended Queue)
        is a sequence container in C++ STL (Standard Template Library)
        allows fast insertion and deletion at both the front and the back.

    //  Internal Implementation


*/
 
/*   Thread safety
        A piece of code or a function behaves correctly when multiple threads access it simultaneously.
        if not Thread safe 
                cause - Race condition , Crashes , Undefined Behavior , data corruption
*/

/*  No bounds checks
        access an index that is out of range, it won’t throw an error — instead, it results in undefined behavior.
        code :- 
            std::deque<int> dq = {10, 20, 30};
            std::cout << dq[1] << "\n";  // ✅ 20 (safe)
            std::cout << dq[10] << "\n"; // ⚠️ No error, but undefined behavior!

        safe Alternative    .at(index)
            std::cout << dq.at(1);   // ✅ Works: prints 20
            std::cout << dq.at(10);  // ❌ Throws std::out_of_range exception

*/
/*  Buffers
        is a temporary storage area , to astored before it's processed or moved.
*/

// Element Access
/*
    dq[i]	    Access ith element (no bounds check)
    dq.at(i)	Bounds-checked access
    dq.front()	First element
    dq.back()	Last element
    */
   
   // key characteristics
   /*
   Random Access                       in constant time 
   Insertion / Delection(front/back)    O(1)
   insertion / Delection(Middle)        O(n)
   
   Memory               Multiple chunks of memory(not contiguous like vector)
   Thread Safety        Not thread-safe
   */ 
  
  // Key operation
  /*
  | Operation         | Function               | Time |
  
  | Insert at back    | dq.push_back(x)        | O(1) |
  | Insert at front   | dq.push_front(x)       | O(1) |
  | Delete from back  | dq.pop_back()          | O(1) |
  | Delete from front | dq.pop_front()         | O(1) |
  | Access front/back | dq.front() / dq.back() | O(1) |
  | Access element    | dq[i], dq.at(i)        | O(1) |
  | Clear all         | dq.clear()             | O(n) |
  | Resize deque      | dq.resize(n)           | O(n) |
  
  */
 
     /*
         | Feature        | vector     | deque    | list     |
         | Random Access  | ✅        | ✅       | ❌      |
         | Front Insert   | ❌ O(n)   | ✅ O(1)  | ✅ O(1) |
         | Back Insert    | ✅ O(1)   | ✅ O(1)  | ✅ O(1) |
         | Cache Locality | ✅        | ❌       | ❌      |


        internal implementation
            dynamic array pointer to fixed-size arrays.
            allows - Fast expansion at both ends
            Reasonable memory usage
            Good cache performance - sequential access
     */



int main() {

    // Syntax
    std::deque <int> dq;

    // Constructors
        deque<int> dq1;                         // empty deque
        deque<int> dq2(5);                      // deque of size 5 (all zeros)
        deque<int> dq3(8, 100);                 // {100, 100, 100, 100, 100}
        deque<int> dq4 = {1, 2, 3, 4};          // initializer list
        deque<int> dq5(dq3.begin(), dq3.end()); // range constructor
        deque<int> dq6(dq3.begin() ,dq3.end()); // copy constructor
        deque<int> dq8(move(dq4));              // Move Constructor

    // Automatically called when deque goes out of scope
    //~deque();   // releases all allocated memory


    // Element Access
    deque<int> dq = {10, 20, 30, 40, 50, 60, 70};
            // Access elements
        cout << dq[0];      // 10 (no bounds checking)
        cout << dq.at(1);   // 20 (with bounds checking)
        cout << dq.front(); // 10 (first element)
        cout << dq.back();  // 50 (last element)

     
    // Capacity Function
         dq.size();            // No. of elements
         dq.empty();           // true if dq is empty
    
    // Iterators
        dq.begin() , dq.end();         // Forward iteration
        dq.rbegin(), dq.rend();        // Reverse iteration
    
    // Range loop 
        for (int xp : dq) cout << xp << " ";

    // Modifiers
        // Add elements
        dq.push_back(10);  // Add at end: {10}
        dq.push_front(5);  // Add at front: {5, 10}

        // Emplace (c++11+)
        dq.emplace_back(x);      // Insert at back (faster than push_back)
        dq.emplace_front(x);     // Insert at front

        // Remove elements
        dq.pop_back();     // Remove from end: {0, 5, 10}
        dq.pop_front();    // Remove from front: {5, 10}

        // Insert and erase
        dq.insert(dq.begin() + 1, 7);   // 
        dq.erase(dq.begin());           // 
        dq.erase(dq.begin() + 1);  // erase single element 
        dq.erase(dq.begin(), dq.begin() + 2);  // erase range
        dq.clear();                     // Empty deque


        // Swap
            deque<int> ddq1 = {1, 2, 3, 4};
            deque<int> ddq2 = {4, 6, 7, 8};

            ddq1.swap(ddq2);   // ddq1 = {4, 6, 7, 8} & ddq2 = {1, 2, 3, 4}
            swap(ddq1 , ddq2); // same effect 

    // Iterators -
        // Forward iterators
        auto it_begin = dq.begin();    // Points to first element
        auto it_end = dq.end();        // Points to past-the-end

        // Reverse iterators
        auto it_rbegin = dq.rbegin();  // Points to last element
        auto it_rend = dq.rend();      // Points to before-first

        // Constant iterators (read-only)
        auto it_cbegin = dq.cbegin();
        auto it_cend = dq.cend();
        auto it_crbegin = dq.crbegin();
        auto it_crend = dq.crend();


    deque<int> dq7 = {1, 2, 3, 4, 5, 65, 7, 8, 9, 10};
        //Forward
        for(auto it = dq.begin(); it != dq.end(); it++){
            cout << *it << " ";
        }

        // Reverse 
        for(auto it = dq.rbegin(); it != dq.rend(); it++){
            cout << *it << " ";
        }

        // Range-based for loop
        for(int num : dq){
            cout << num << " ";
        }

        // shrink_to_fit() - reduce memory usage
        dq.shrink_to_fit();     // Request to minimize capacity


        // assign() - replace contents
            dq1.assign(5, 100);     // {100, 100, 100, 100, 100}
            dq2.assign({7, 8, 9});  // {7, 8, 9}


    // Emplace (Efficient Construction)
        deque<pair<int, string>> dqq;

        // More efficient than push_back(make_pair(1, "one"))
            dqq.emplace_back(1, "one");
            dqq.emplace_front(0, "zero");

        // Emplace at position
        dqq.emplace(dqq.begin() + 1, 2, "two");

    return 0;
}