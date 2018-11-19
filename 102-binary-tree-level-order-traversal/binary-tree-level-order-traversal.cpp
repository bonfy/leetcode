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
        queue<TreeNode*> tree;
        vector<vector<int>> ans;
        vector<int> level;
        if (!root) {
            return ans;
        }
        tree.emplace(root);
        tree.emplace(nullptr);
        TreeNode* p = root;
        while(p || !tree.empty()) {
            p = tree.front();
            tree.pop();
            if (!p) {
                ans.emplace_back(level);
                level.clear();
                if (!tree.empty()) {
                    tree.emplace(nullptr);
                }
            } else {
                level.emplace_back(p->val);
                if (p->left) {
                    tree.emplace(p->left);
                }
                if (p->right) {
                    tree.emplace(p->right);
                }
            }
        }
        return ans;
    }
};
