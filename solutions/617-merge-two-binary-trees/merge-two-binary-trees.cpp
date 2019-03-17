// Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
//
// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
//
// Example 1:
//
//
// Input: 
// 	Tree 1                     Tree 2                  
//           1                         2                             
//          / \                       / \                            
//         3   2                     1   3                        
//        /                           \   \                      
//       5                             4   7                  
// Output: 
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \ 
// 	 5   4   7
//
//
//  
//
// Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.emplace(t1, t2);
        while (stk.size()) {
            auto [l, r] = stk.top();
            stk.pop();
            l->val += r->val;
            if (!l->left) {
                l->left = r->left;
            } else if (r->left) {
                stk.emplace(l->left, r->left);
            }
            if (!l->right) {
                l->right = r->right;
            } else if (r->right) {
                stk.emplace(l->right, r->right);
            }
        }
        return t1;
    }
};
