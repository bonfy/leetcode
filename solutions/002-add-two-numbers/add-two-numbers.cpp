// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra = 0, v1 = 0, v2 = 0, sum = 0;
        ListNode* p = new ListNode(0);
        auto& ret = p->next;
        while (l1 != NULL || l2 != NULL) {
            v1 = getValAndMove(l1);
            v2 = getValAndMove(l2);
            sum = v1 + v2 + extra;
            p->next = new ListNode(sum % 10);
            p = p->next;
            extra = sum / 10;
        }
        if (extra > 0) {
            p->next = new ListNode(extra);
        }
        return ret;
    }
    inline int getValAndMove(ListNode* &l) {
        int x = 0;
        if (l != NULL) {
            x = l->val;
            l = l->next;
        }
        return x;
    }
};
