// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node values.
//
// Example 1: 
//
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
//
//
// The following are two duplicate subtrees:
//
//
//       2
//      /
//     4
//
//
// and
//
//
//     4
//
// Therefore, you need to return above trees' root in the form of a list.


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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> freq;
        vector<TreeNode*> ans;
        form(root, freq, ans);
        return ans;
    }
    string form(TreeNode* root, unordered_map<string, int>& freq, vector<TreeNode*>& ans) {
        if (!root) return {};
        string s("+" + to_string(root->val) + "(" + form(root->left, freq, ans) + ")" + form(root->right, freq, ans) + "-");
        if (freq[s]++ == 1) {
            ans.emplace_back(root);
        }
        return s;
    }
};
