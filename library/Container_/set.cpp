#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Set
// container stores unique elements in sorted order.
// implementation - self Balancing Binary Search Trees - Red-Black Trees

// Searching , insertion , and deletion - O(log n)
// Avoid Duplicates
// ascending order by default, ordering - custom rule(comparator)

template <typename T>
// Syntax-
set<T> s;

// Custom comparator to sort in descending order
struct CompareDesc {
    bool operator()(const int a, const int b) const {
        return a > b;
    }
};

int main()
{
    // empty set
    set<int> s1;

    // Initializer list
    set<int> s2 = {5, 2, 8, 1, 9};

    // Inserting an element
    s1.insert(1);

    // From another container
    vector<int> vec = {3, 1, 4, 1, 5};
    set<int> s3(vec.begin(), vec.end());
    std::set<int> mySet;

    // Insert elements (duplicates are ignored)
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(2); // This insertion will be ignored

    // Iterate through the set (it's sorted!)
    std::cout << "Set elements: ";
    for (int num : mySet)
    {
        std::cout << num << " "; // Output will be: 2 5 8
    }
    std::cout << std::endl;

    // Check if an element exists
    if (mySet.find(5) != mySet.end())
    {
        std::cout << "5 is in the set." << std::endl;
    }

    // Erase an element
    mySet.erase(5);

    // Count elements (returns 0 or 1)
    std::cout << "Count of 8: " << mySet.count(8) << std::endl;
    std::cout << "Count of 5: " << mySet.count(5) << std::endl;


    // Declare a set using the custom comparator
    std::set<int, CompareDesc> myDescSet;

    myDescSet.insert(3);
    myDescSet.insert(1);
    myDescSet.insert(4);
    myDescSet.insert(2);

    std::cout << "Set elements (descending): ";
    for (int num : myDescSet) {
        std::cout << num << " "; // Output will be: 4 3 2 1
    }
    std::cout << std::endl;

    return 0;
}