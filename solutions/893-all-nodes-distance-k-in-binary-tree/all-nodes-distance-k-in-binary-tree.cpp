// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//
// Output: [7,4,1]
//
// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.
//
//
//
// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
//
//
//  
//
// Note:
//
//
// 	The given tree is non-empty.
// 	Each node in the tree has unique values 0 <= node.val <= 500.
// 	The target node is a node in the tree.
// 	0 <= K <= 1000.
//
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> st;
        find(root, parent);
        vector<int> ans;
        dfs(target, K, st, parent, ans);
        return ans;
    }
    void find(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            find(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            find(root->right, parent);
        }
    }
    void dfs(TreeNode* target, int k, unordered_set<TreeNode*>& st, unordered_map<TreeNode*, TreeNode*>& parent, vector<int>& ans) {
        if (!target) return;
        if (st.count(target)) return;
        st.emplace(target);
        if (k == 0) {
            ans.emplace_back(target->val);
            return;
        }
        if (target->left) {
            dfs(target->left, k - 1, st, parent, ans);
        }
        if (target->right) {
            dfs(target->right, k - 1, st, parent, ans);
        }
        auto p = parent[target];
        if (p) {
            dfs(p, k - 1, st, parent, ans);
        }
    }
};
