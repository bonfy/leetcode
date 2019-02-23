// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if (!root) return 0;
        q.emplace(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left and !p->left->left and !p->left->right) {
                ans += p->left->val;
            }
            if (p->left) q.emplace(p->left);
            if (p->right) q.emplace(p->right);
        }
        return ans;
    }
};
