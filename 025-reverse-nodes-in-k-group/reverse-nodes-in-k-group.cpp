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
        ListNode* prev = &dummy;
        ListNode* fast = prev;
        dummy.next = head;
        int t = 0;
        while (fast->next) {
            t++;
            fast = fast->next;
            if (t == k) {
                t = 0;
                auto todo = fast->next;
                auto slow = prev->next;
                auto h = todo;
                while (slow != todo) {
                    auto next = slow->next;
                    slow->next = h;
                    h = slow;
                    slow = next;
                }
                auto next_p = prev->next;
                prev->next = h;
                prev = next_p;
                fast = next_p;
            }
        }
        return dummy.next;
    }
};
