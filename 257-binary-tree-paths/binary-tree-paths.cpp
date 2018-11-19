// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        addpath(root, "", ans);
        return ans;
    }
    void addpath(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.emplace_back(path);
        }
        addpath(root->left, path + "->", ans);
        addpath(root->right, path + "->", ans);
    }
};
