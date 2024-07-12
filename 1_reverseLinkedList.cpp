#include <iostream>
 #include <wchar.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev one step forward
            current = next;       // Move current one step forward
        }
        
        return prev; // Prev becomes the new head
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
