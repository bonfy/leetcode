// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans{};
        visit(root, &ans, 0);
        return ans;
    }
    void visit(TreeNode* root, vector<int>* ans, int d) {
        if (root == nullptr) {
            return;
        }
        if (d == ans->size()) {
            ans->emplace_back(root->val);
        } else {
            ans->at(d) = root->val;
        }
        visit(root->left, ans, d+1);
        visit(root->right, ans, d+1);
    }
};
