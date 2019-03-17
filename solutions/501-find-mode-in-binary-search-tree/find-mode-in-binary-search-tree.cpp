// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// 	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
//  
//
// For example:
// Given BST [1,null,2,2],
//
//
//    1
//     \
//      2
//     /
//    2
//
//
//  
//
// return [2].
//
// Note: If a tree has more than one mode, you can return them in any order.
//
// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        int maxf = 0;
        int cnt = 0;
        int prev = INT_MAX;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (p->val == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxf = max(maxf, cnt);
            prev = p->val;
            p = p->right;
        }
        vector<int> ans;
        p = root;
        prev = INT_MAX;
        cnt = 0;
        while (p || !stk.empty()) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (p->val == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt == maxf) {
                ans.emplace_back(p->val);
            }
            prev = p->val;
            p = p->right;
        }
        return ans;
    }
};
