// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int j = lists.size() - 1;
        while (j > 0) {
            for (int i = 0; i < j; ++i, --j) {
                lists[i] = merge2(lists[i], lists[j]);
            }
        }
        return lists[0];
    }
    ListNode* merge2(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        auto p = &dummy;
        while (a || b) {
            if (!b || (a && b && a->val < b->val)) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
