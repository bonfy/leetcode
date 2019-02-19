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
        if (!root) return {};
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.emplace_back(path);
        } else {
            if (root->left) {
                dfs(root->left, path + "->", ans);
            }
            if (root->right) {
                dfs(root->right, path + "->", ans);
            }
        }
    }
};
