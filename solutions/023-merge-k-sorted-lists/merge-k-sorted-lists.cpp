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
        /*
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_pq(cmp);
        ListNode dummy(0);
        ListNode* p = &dummy;
        for (auto l: lists) {
            if (!l) continue;
            min_pq.emplace(l);
        }
        while (!min_pq.empty()) {
            auto l = min_pq.top();
            min_pq.pop();
            p->next = l;
            p = p->next;
            if (l->next) min_pq.emplace(l->next);
        }
        return dummy.next;
        */
        int n = lists.size();
        if (!n) return nullptr;
        int last = n - 1;
        while (last != 0) {
            int i = 0, j = last;
            while (i < j) {
                lists[i] = merge2(lists[i++], lists[j--]);
            }
            last = j;
        }
        return lists[0];
    }
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (l1 || l2) {
            if ((l1 && l2 && l1->val < l2->val) || !l2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
