#include<iostream>
using namespace std;



// Fast-Slow (Tortoise-Hare) Two Pointer Techniques

    // clear approach - two pointers traverse a data structure at different speeds.
    // technique - particularly - middle elements 

        // Concept-
            // Slow pointer - 1 step at time
            // Fast pointer - 2 step at time
            
            // Fast pointer reaches - end , slow pointer - at middle


    
// 1. Cycle Detection in Linked Lists

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if(!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}


// 2.  Find Cycle starting Point
ListNode* detectCycle(ListNode* head) {
    if(!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow -> next;
        fast = fast -> next;

        if (slow == fast) {
            slow = fast;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

}