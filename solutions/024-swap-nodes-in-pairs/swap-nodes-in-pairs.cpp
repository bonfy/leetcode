// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//  
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* fast = &dummy;
        ListNode* prev = &dummy;
        fast->next = head;
        int cnt = 0;
        while (fast->next) {
            cnt++;
            fast = fast->next;
            if (cnt == 2) {
                cnt = 0;
                ListNode* slow = prev->next;
                ListNode* todo = fast->next;
                ListNode* h = todo;
                while (slow != todo) {
                    ListNode* next = slow->next;
                    slow->next = h;
                    h = slow;
                    slow = next;
                }
                ListNode* next_p = prev->next;
                prev->next = h;
                prev = next_p;
                fast = next_p;
            }
        }
        return dummy.next;
    }
};
