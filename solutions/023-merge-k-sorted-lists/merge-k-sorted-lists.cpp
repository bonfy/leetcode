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
    }
};
