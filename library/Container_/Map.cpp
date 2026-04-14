
#include <iostream>
#include <map>
#include <string>
#include <functional> // for std::greater




// MAP

// associative container stores elements formed by a combination of key and mapped value.
// implemented  sorted , balanced binary tree (red black tree)

// key characteristics
    // sorted Order  - elementsb automatically sorted by keys
    // unique keys -  no two elements - same key , duplicate keys,
    // Direct Access - elements - accessed directly by key , lookup insection & deletion 
    // Key-Value - element - pair<const Key, T>, where Key - type of key , T - type mapped value.


#include <map> // Required header

// Syntax: std::map<KeyType, ValueType, Comparator, Allocator>
// The last two (Comparator and Allocator) have default values.

std::map<int, std::string> studentMap; // Map with int keys and string values
std::map<std::string, double> priceMap; // Map with string keys and double values



int main() {
    // 1. Declaration and Initialization
    std::cout << "=== 1. Declaration and Initialization ===\n";
    std::map<int, std::string> studentMap;
    std::map<std::string, int> ageMap = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};

    // 2. Inserting Elements
    std::cout << "\n=== 2. Inserting Elements ===\n";
    studentMap.insert(std::make_pair(101, "Alice"));
    studentMap.insert({102, "Bob"});
    studentMap[103] = "Charlie";
    studentMap[104] = "David";
    studentMap[101] = "Alicia"; // This updates the value for key 101

    // 3. Accessing Elements
    std::cout << "\n=== 3. Accessing Elements ===\n";
    std::cout << "studentMap[103]: " << studentMap[103] << std::endl;
    std::cout << "ageMap.at(\"Alice\"): " << ageMap.at("Alice") << std::endl;

    // 4. Checking if key exists using find()
    std::cout << "\n=== 4. Checking Key Existence ===\n";
    auto it = studentMap.find(105);
    if (it != studentMap.end()) {
        std::cout << "Key 105 found: " << it->second << std::endl;
    } else {
        std::cout << "Key 105 not found!" << std::endl;
    }

    // 5. Iterating through the map
    std::cout << "\n=== 5. Iterating (Sorted Order) ===\n";
    std::cout << "studentMap:\n";
    for (const auto& pair : studentMap) {
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "ageMap:\n";
    for (const auto& pair : ageMap) {
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }

    // 6. Size and Empty check
    std::cout << "\n=== 6. Size and Capacity ===\n";
    std::cout << "studentMap size: " << studentMap.size() << std::endl;
    std::cout << "Is studentMap empty? " << (studentMap.empty() ? "Yes" : "No") << std::endl;

    // 7. Removing Elements
    std::cout << "\n=== 7. Removing Elements ===\n";
    std::cout << "Erasing key 102: " << studentMap.erase(102) << " element removed\n";
    
    auto eraseIt = studentMap.find(103);
    if (eraseIt != studentMap.end()) {
        studentMap.erase(eraseIt);
        std::cout << "Element with key 103 erased using iterator\n";
    }

    // 8. Custom Comparator (Descending Order)
    std::cout << "\n=== 8. Custom Sorting (Descending) ===\n";
    std::map<int, std::string, std::greater<int>> descMap;
    descMap[300] = "Three Hundred";
    descMap[100] = "One Hundred";
    descMap[200] = "Two Hundred";

    for (const auto& pair : descMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 9. Lower and Upper Bound
    std::cout << "\n=== 9. Lower and Upper Bound ===\n";
    std::map<int, std::string> numMap = {{10, "Ten"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}};
    
    auto lb = numMap.lower_bound(25);
    auto ub = numMap.upper_bound(35);
    
    std::cout << "Lower bound of 25: " << lb->first << " -> " << lb->second << std::endl;
    std::cout << "Upper bound of 35: " << ub->first << " -> " << ub->second << std::endl;

    // 10. Count and Contains (C++20)
    std::cout << "\n=== 10. Count and Contains ===\n";
    std::cout << "Number of elements with key 101: " << studentMap.count(101) << std::endl;
    
    #if __cplusplus >= 202002L
    std::cout << "Contains key 104? " << (studentMap.contains(104) ? "Yes" : "No") << std::endl;
    #endif

    // 11. Clear the map
    std::cout << "\n=== 11. Clearing the Map ===\n";
    std::map<int, std::string> tempMap = {{1, "One"}, {2, "Two"}};
    std::cout << "Before clear - Size: " << tempMap.size() << std::endl;
    tempMap.clear();
    std::cout << "After clear - Size: " << tempMap.size() << std::endl;

    return 0;
}

// map
    // Declaration and initialization
    // Inserting elements (multiple methods)
    // Accessing elements (safe and unsafe methods)
    // Checking if a key exists
    // Iterating through the map
    // Size and capacity checks
    // Removing elements (by key and iterator)
    // Custom sorting with comparators
    // Lower and upper bound operations
    // Count and contains operations
    // Clearing the map