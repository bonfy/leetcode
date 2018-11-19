// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans{};
        unordered_map<int, vector<int>> m{};
        visit(root, &m, 0);
        reverse(m, &ans);
        return ans;
    }
    void visit(TreeNode* root, unordered_map<int, vector<int>>* m, int d) {
        if (root == nullptr) {
            return;
        }
        if (m->find(d) == m->end()) {
            m->emplace(d, vector<int>{root->val});
        }
        else {
            m->at(d).emplace_back(root->val);
        }
        visit(root->left, m, d + 1);
        visit(root->right, m, d + 1);
        
    }
    void reverse(unordered_map<int, vector<int>>& m, vector<vector<int>>* ans) {
        int s = m.size();
        for (int i = s - 1; i >= 0; i--) {
            ans->emplace_back(m[i]);
        }
    }
};
