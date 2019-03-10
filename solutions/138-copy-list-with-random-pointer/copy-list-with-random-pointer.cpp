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


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, Node*> image;
        for (auto l = head; l; l = l->next) {
            image[l] = new Node(l->val, nullptr, nullptr);
        }
        for (auto l = head; l; l = l->next) {
            image[l]->next = image[l->next];
            image[l]->random = image[l->random];
        }
        return image[head];
    }
};
