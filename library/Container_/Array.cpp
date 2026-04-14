#include <iostream>

// C++11 , container 
#include<array>

using namespace std;


int main() {

    std:: array<int , 3> a = {10 , 20 , 30};
    std:: array<int , 3> b {};

    cout << a[0];
    cout << a.at(3);


    /*
        .at(index)     -   safe access with bounds checking
        [](Subscript operator) - return element without bounds checking
        .size()        -   Number of elements 
        .front()       -   First element 
        .back()        -   Last element
        .fill(value)   -   Set all elements to same value
        .data()        -   Return pointer to internal array
        .empty()       -   Checks if arrays is empty (always false unless size is 0)

        Iterators
            * begin() , end() - both are pointer 
                begin()  -  starting 
                end()    -  ending
                
            * Range-based loop
                for (int x : arr) {
                    cout << x << "  ";
                }

            * rbegin() , rend()   -  reverse iterators , both are pointers
                rbegin() - 
                rend()   - 

            * cbegin() / cend()   -  constant iterators
                cbegin() - 
                cend()   - 

        Comparison Operators
            array<int , 3> a = {1 , 2 , 3};
            array<int , 3> b = {1 , 2 , 4};

            cout << (a == b); // false
            cout << (a < b);  // true

        Capacity
            size()  - Number of elements 
            empty() - True , size == 0

        Modifiers
            fil(val)   - Fill array with val
            swap(arr2) - Swap with another array

        Structured Binding (C++17)
            array<int, 3> arr = {10 , 20 , 30};
            auto [x , y , z] = arr;

        Swap 
            array<int , 3> a = {1 , 2, 3};
            array<int , 3> b = {4 , 5, 6};
            a.swap(b);   // a = {4, 5, 6} , b = {1, 2, 3}

        Using with STL Algorithms
            sort(arr.begin() , arr.end());
            reverse(arr.begin() , arr.end());
            find(arr.begin() , arr.end());

        Initialization Methods
            array<int, 5> a1 = {1, 2, 3, 4, 5};
            array<int, 5> a2{};
            array<int, 5> a3 = {0};

        
        Memory Layout and Internal Working
            std::array<T, N>  -  wrapper over a raw array( T[N])
            stores elements contiguously in stack memory , 
            no dynamic memory allocation - extremely fast and cache-friendly

        Internal Structure
            template<typename T, std::size_t N>
            struct array {
                T elements[N];   // underlying raw array

                // size() , at() , [], etc/ .
            };

        Constexpr Support(C++11 and above)
                constexpr - keyword - indicates a values , variable or function - evaluted at compile time
            * std::array  - used  constexpr 
                constexpr std::array<int , 3> arr = { 1, 2, 3};
            * Enables complie-time computation:
                constexpr int sum = arr[0] + arr[1] + arr[2];

        Tuple-Like Access(C++17)
            get<index>(array)


    */

    return 0;
}