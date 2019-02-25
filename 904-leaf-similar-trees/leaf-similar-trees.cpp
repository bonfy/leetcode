// Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
//
//
//
// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
//
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
//
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
//
//  
//
// Note:
//
//
// 	Both of the given trees will have between 1 and 100 nodes.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        auto v1 = f(root1);
        auto v2 = f(root2);
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
    vector<int> f(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            if (!p->left && !p->right) ans.emplace_back(p->val);
            if (p->right) stk.emplace(p->right);
            if (p->left) stk.emplace(p->left);
        }
        
        return ans;
    }
};
