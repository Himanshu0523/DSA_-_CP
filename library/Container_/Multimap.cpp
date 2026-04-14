#include <iostream>     // For input/output operations
#include <map>          // For multimap and map containers
#include <string>       // For std::string
#include <utility>      // For std::pair and std::make_pair
#include <algorithm>    // For std::for_each and other algorithms
#include <ctime>        // For time-related functions
#include <vector>       // For std::vector (optional, for comparisons)



// std::multimap is an associative container that stores elements in a key-value format where multiple elements can have the same key. It's part of the C++ Standard Template Library (STL) and is defined in the <map> header.

// Key Characteristics
// Sorted structure: Elements are always sorted by key

// Duplicate keys allowed: Unlike std::map, multiple elements can have the same key

// Balanced BST: Typically implemented as a red-black tree

// Bidirectional iterators: Supports forward and backward traversal



using namespace std;

int main() {
    cout << "=== Multimap Examples ===" << endl << endl;
    
    // Example 1: Basic multimap operations
    cout << "1. Basic Multimap Operations:" << endl;
    multimap<int, string> studentScores;
    
    // Inserting elements
    studentScores.insert({101, "Alice"});
    studentScores.insert({102, "Bob"});
    studentScores.insert({101, "Charlie"});  // Duplicate key
    studentScores.insert({103, "David"});
    studentScores.insert({101, "Eva"});      // Another duplicate key
    
    // Display all elements
    cout << "All student scores:" << endl;
    for (const auto& pair : studentScores) {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }
    cout << endl;
    
    // Example 2: Finding and counting elements
    cout << "2. Finding and Counting Elements:" << endl;
    int searchId = 101;
    cout << "Number of students with ID " << searchId << ": " 
         << studentScores.count(searchId) << endl;
    
    // Using equal_range to get all elements with same key
    auto range = studentScores.equal_range(searchId);
    cout << "Students with ID " << searchId << ":" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "  - " << it->second << endl;
    }
    cout << endl;
    
    // Example 3: Erasing elements
    cout << "3. Erasing Elements:" << endl;
    cout << "Size before erase: " << studentScores.size() << endl;
    
    // Erase all elements with key 101
    size_t erased = studentScores.erase(101);
    cout << "Erased " << erased << " elements with key 101" << endl;
    cout << "Size after erase: " << studentScores.size() << endl;
    cout << endl;
    
    // Example 4: Custom comparator
    cout << "4. Multimap with Custom Comparator (Descending Order):" << endl;
    multimap<int, string, greater<int>> descendingMap;
    
    descendingMap.insert({3, "Three"});
    descendingMap.insert({1, "One"});
    descendingMap.insert({2, "Two"});
    descendingMap.insert({1, "Another One"});  // Duplicate
    
    for (const auto& pair : descendingMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;
    
    // Example 5: Event logging with timestamps
    cout << "5. Event Logging Example:" << endl;
    multimap<time_t, string> eventLog;
    
    time_t now = time(nullptr);
    eventLog.emplace(now, "System started");
    eventLog.emplace(now + 2, "User logged in");
    eventLog.emplace(now, "Configuration loaded");  // Same timestamp
    eventLog.emplace(now + 5, "File processed");
    
    cout << "Event log (chronological order):" << endl;
    for (const auto& event : eventLog) {
        cout << "Time: " << event.first << " - Event: " << event.second << endl;
    }
    cout << endl;
    
    // Example 6: Using lower_bound and upper_bound
    cout << "6. Using lower_bound and upper_bound:" << endl;
    multimap<int, string> numMap = {
        {10, "ten"},
        {20, "twenty"},
        {20, "TWENTY"},
        {30, "thirty"},
        {40, "forty"}
    };
    
    int target = 20;
    auto low = numMap.lower_bound(target);
    auto up = numMap.upper_bound(target);
    
    cout << "Elements with key " << target << ":" << endl;
    for (auto it = low; it != up; ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << endl;
    
    // Example 7: Capacity methods
    cout << "7. Capacity Methods:" << endl;
    multimap<int, string> emptyMap;
    multimap<int, string> filledMap = {{1, "a"}, {2, "b"}};
    
    cout << "emptyMap empty? " << (emptyMap.empty() ? "Yes" : "No") << endl;
    cout << "filledMap empty? " << (filledMap.empty() ? "Yes" : "No") << endl;
    cout << "filledMap size: " << filledMap.size() << endl;
    cout << "Max possible size: " << filledMap.max_size() << endl;
    cout << endl;
    
    // Example 8: Clear and swap
    cout << "8. Clear and Swap Operations:" << endl;
    multimap<int, string> map1 = {{1, "one"}, {2, "two"}};
    multimap<int, string> map2 = {{3, "three"}, {4, "four"}};
    
    cout << "Before swap - map1 size: " << map1.size() 
         << ", map2 size: " << map2.size() << endl;
    
    map1.swap(map2);
    cout << "After swap - map1 size: " << map1.size() 
         << ", map2 size: " << map2.size() << endl;
    
    map1.clear();
    cout << "After clear - map1 size: " << map1.size() << endl;
    
    return 0;
}