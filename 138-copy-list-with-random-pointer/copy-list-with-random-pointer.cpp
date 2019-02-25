// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.
//
//  
//
// Example 1:
//
//
//
//
// Input:
// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
// Explanation:
// Node 1's value is 1, both of its next and random pointer points to Node 2.
// Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
//
//
//  
//
// Note:
//
//
// 	You must return the copy of the given head as a reference to the cloned list.
//


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        unordered_map<RandomListNode*, RandomListNode*> image;
        for (RandomListNode* l = head; l; l = l->next) {
            if (!image.count(l)) {
                image[l] = new RandomListNode(l->label);
            }
        }
        for (RandomListNode* l = head; l; l = l->next) {
            image[l]->next = image[l->next];
            image[l]->random = image[l->random];
        }
        return image[head];
    }
};
