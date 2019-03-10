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
        if (!root) return 0;
        /*
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        */
        queue<TreeNode*> q;
        q.emplace(root);
        int ans = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left && !p->left->left && !p->left->right) ans += p->left->val;
            if (p->left) q.emplace(p->left);
            if (p->right) q.emplace(p->right);
        }
        return ans;
    }
};
