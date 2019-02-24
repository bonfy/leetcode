// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* mid = p1;
        p1 = p1->next;
        mid->next = nullptr;
        p2 = nullptr;
        while (p1) {
            ListNode* next = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = next;
        }
        p1 = head;
        while (p2) {
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;
            p1->next = p2;
            p2->next = n1;
            p1 = n1;
            p2 = n2;
        }
    }
};
