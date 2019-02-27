// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow;
        slow = slow->next;
        mid->next = nullptr;
        auto l = sortList(head);
        auto r = sortList(slow);
        return merge(l, r);
    }
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        auto p = &dummy;
        while (l || r) {
            if ((l && r && l->val < r->val) || !r) {
                p->next = l;
                l = l->next;
            } else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
