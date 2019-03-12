// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(0, 0, inorder.size(), preorder, inorder);
    }
    TreeNode* build(int pre, int ins, int ine, vector<int>& preorder, vector<int>& inorder) {
        if (pre >= preorder.size() || ins >= ine) return nullptr;
        int n = preorder[pre];
        TreeNode* root = new TreeNode(n);
        int p = mp[n];
        root->left = build(pre + 1, ins, p, preorder, inorder);
        root->right = build(pre + p - ins + 1, p + 1, ine, preorder, inorder);
        return root;
    }
    unordered_map<int, int> mp;
};
