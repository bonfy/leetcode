// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        auto p = &dummy;
        p->next = head;
        auto prev = p;
        int k = 0;
        while (k != m && p->next) {
            prev = p;
            p = p->next;
            ++k;
        }
        while (k != n && p->next) {
            p = p->next;
            ++k;
        }
        auto todo = p->next;
        p = prev->next;
        auto h = todo;
        while (p != todo) {
            auto next = p->next;
            p->next = h;
            h = p;
            p = next;
        }
        prev->next = h;
        return dummy.next;
    }
};
