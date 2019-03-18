// Given a binary tree, return the postorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [3,2,1]
//
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.emplace(root);
        stack<int> rans;
        while (stk.size()) {
            auto p = stk.top();
            stk.pop();
            rans.emplace(p->val);
            ans.emplace_back(p->val);
            if (p->left) {
                stk.emplace(p->left);
            }
            if (p->right) {
                stk.emplace(p->right);
            }
        }
        reverse(ans.begin(), ans.end());
        vector<int> ans2;
        while (!rans.empty()) {
            ans2.emplace_back(rans.top());
            rans.pop();
         
        }
        return ans2;
    }
};
