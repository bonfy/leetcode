// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans{};
        stack<TreeNode*> q;
        if (root == nullptr) {
            return ans;
        }

        TreeNode* p = root;
        while (!q.empty() || p) {
            while(p) {
                q.emplace(p);
                p = p->left;
            }
            p = q.top();
            q.pop();
            ans.emplace_back(p->val);
            p = p->right;
        }
        return ans;
    }
};
