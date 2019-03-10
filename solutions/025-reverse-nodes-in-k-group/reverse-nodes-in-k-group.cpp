// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        auto p = &dummy;
        p->next = head;
        auto prev = p;
        int cnt = 0;
        while (p->next) {
            p = p->next;
            cnt++;
            if (cnt == k) {
                cnt = 0;
                auto slow = prev->next;
                auto todo = p->next;
                auto h = todo;
                while (slow != todo) {
                    auto next = slow->next;
                    slow->next = h;
                    h = slow;
                    slow = next;
                }
                auto new_prev = prev->next;
                prev->next = h;
                prev = new_prev;
                p = prev;
            }
        }
        return dummy.next;
    }
};
