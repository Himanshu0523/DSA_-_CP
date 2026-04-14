#include<list>
#include<iostream>
using namespace std;


int main(){
    
    //  Declaration
    list<int> l;

    // Initialization with values
    list<int> l1 = {1, 2, 3, 4, 5};
    list<int> l2(5 , 10); // 5 element , each 10


    // add front and back
    l1.push_front(10);   // l1 : 10
    l1.push_back(20);    // l1 : 10 -> 20

    // Insert at specific position
    auto it = l1.begin();
    advance(it , 1);  // Move iterator to position 1
    l1.insert(it , 100); // l1 : 10->100->20


    // Insert multiple values
    l1.insert(l1.begin() , {5, 7, 8});

    // Remove elements satisfying condition
    l.remove_if([](int x) { return x % 2 == 0; }); // Remove even numbers

    // Transfer all element from l2 to l1
    l1.splice(l1.end(), l2);

    // Transfer single element
    auto it = l2.begin();
    l1.splice(l1.begin(), l2, it);

    // Transfer range of element
    auto first = l2.begin();
    auto last = next(first, 2);
    l1.splice(l1.end(), l2, first, last);

    return 0;
}