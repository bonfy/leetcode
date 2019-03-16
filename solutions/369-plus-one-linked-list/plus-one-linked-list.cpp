// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.
//
//
// Example :
//
//
// Input: [1,2,3]
// Output: [1,2,4]
//
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
    ListNode* plusOne(ListNode* head) {
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* p = h;
        stack<ListNode*> stk;
        while (p) {
            stk.emplace(p);
            p = p->next;
        }
        int c = 1;
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            int sum = c;
            sum += p->val;
            c = sum / 10;
            p->val = sum % 10;
        }
        return h->val == 0? h->next: h;
    }
};
