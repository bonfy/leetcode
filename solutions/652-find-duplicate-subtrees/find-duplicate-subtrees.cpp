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
        unordered_map<string, vector<TreeNode*>> mp;
        seralize(root, mp);
        vector<TreeNode*> ans;
        for (auto p: mp) {
            if (p.second.size() > 1) {
                ans.emplace_back(p.second[0]);
            }
        }
        return ans;
    }
    string seralize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mp) {
        if (!root) return "";
        string s = "(" + seralize(root->left, mp) + ")" + to_string(root->val) + "(" + seralize(root->right, mp) + ")";
        mp[s].emplace_back(root);
        return move(s);
    }
};
