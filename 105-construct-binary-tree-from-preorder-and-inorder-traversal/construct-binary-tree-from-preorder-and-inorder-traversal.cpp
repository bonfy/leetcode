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
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        preorder = p;
        inorder = in;
        for (int i = 0; i < inorder.size(); ++i) {
            inpos[inorder[i]] = i;
        }
        
        return construct(0, 0, inorder.size() - 1);
    }
    TreeNode* construct(int pre, int in_s, int in_e) {
            if (pre >= preorder.size() || in_s > in_e) return nullptr;
            TreeNode* root = new TreeNode(preorder[pre]);
            int pos = inpos[preorder[pre]];
            int leftlen = pos - in_s;
            root->left = construct(pre + 1, in_s, pos - 1);
            root->right = construct(pre + leftlen + 1, pos + 1, in_e);
            return root;
    };
    unordered_map<int, int> inpos;
    vector<int> preorder, inorder;
};
