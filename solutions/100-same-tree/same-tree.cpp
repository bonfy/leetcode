// Given two binary trees, write a function to check if they are the same or not.
//
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
// Example 1:
//
//
// Input:     1         1
//           / \       / \
//          2   3     2   3
//
//         [1,2,3],   [1,2,3]
//
// Output: true
//
//
// Example 2:
//
//
// Input:     1         1
//           /           \
//          2             2
//
//         [1,2],     [1,null,2]
//
// Output: false
//
//
// Example 3:
//
//
// Input:     1         1
//           / \       / \
//          2   1     1   2
//
//         [1,2,1],   [1,1,2]
//
// Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        queue<TreeNode*> dp, dq;
        dp.emplace(p);
        dq.emplace(q);
        while (!dp.empty() && !dq.empty()) {
            TreeNode* a = dp.front();
            dp.pop();
            TreeNode* b = dq.front();
            dq.pop();
            if (a->val != b->val) return false;
            if (a->left && b->left) {
                dp.emplace(a->left);
                dq.emplace(b->left);
            } else if (a->left || b->left){
                return false;
            }
            if (a->right && b->right) {
                dp.emplace(a->right);
                dq.emplace(b->right);
            } else if (a->right || b->right){
                return false;
            }
        }
        return dp.empty() && dq.empty();
    }
};
