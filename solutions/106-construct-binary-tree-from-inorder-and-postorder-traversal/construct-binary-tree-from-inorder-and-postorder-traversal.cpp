// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(postorder.size() - 1, 0, inorder.size(), inorder, postorder);
    }
    unordered_map<int, int> mp;
    TreeNode* build(int post, int ins, int ine, vector<int>& inorder, vector<int>& postorder) {
        if (post < 0 || ins >= ine) return nullptr;
        TreeNode* root = new TreeNode(postorder[post]);
        int p = mp[postorder[post]];
        root->left = build(post - (ine - p), ins, p, inorder, postorder);
        root->right = build(post - 1, p + 1, ine, inorder, postorder);
        return root;
    }
};
