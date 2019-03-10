// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
//
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
//
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
//
// Return true if and only if the nodes corresponding to the values x and y are cousins.
//
//  
//
// Example 1:
//
//
//
// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
//
//
//
// Example 2:
//
//
//
// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
//
//
//
// Example 3:
//
//
//
//
// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
//
//  
//
//
//
// Note:
//
//
// 	The number of nodes in the tree will be between 2 and 100.
// 	Each node has a unique integer value from 1 to 100.
//
//
//
//
//  
//
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> p, d;
        d[root->val] = 0;
        p[root->val] = INT_MAX;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!p.count(x) && !p.count(y) && q.size()) {
            for (int i = q.size(); i > 0; --i) {
                auto u = q.front();
                q.pop();
                if (u->left) {
                    p[u->left->val] = u->val;
                    d[u->left->val] = d[u->val] + 1;
                    q.emplace(u->left);
                }
                if (u->right) {
                    p[u->right->val] = u->val;
                    d[u->right->val] = d[u->val] + 1;
                    q.emplace(u->right);
                }
            }
        }
        return p.count(x) && p.count(y) && d.count(x) && d.count(y) && p[x] != p[y] && d[x] == d[y];
    }
};
