// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
    void helper(TreeNode* root, int d, vector<vector<int>>& ans) {
        if (!root) return;
        if (ans.size() <= d) {
            ans.emplace_back(vector<int>{root->val});
        } else {
            ans[d].emplace_back(root->val);
        }
        helper(root->left, d + 1, ans);
        helper(root->right, d + 1, ans);
    }
};
