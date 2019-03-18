// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than the node's key.
// 	The right subtree of a node contains only nodes with keys greater than the node's key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
// Example 1:
//
//
// Input:
//     2
//    / \
//   1   3
// Output: true
//
//
// Example 2:
//
//
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.
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
    bool isValidBST(TreeNode* root) {
        /*
        if (!root) return true;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        TreeNode* prev = nullptr;
        while (p || !stk.empty()) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (prev && prev->val >= p->val) return false;
            prev = p;
            p = p->right;
        }
        return true;
        */
        return valid(root, nullptr, nullptr);
    }
    bool valid(TreeNode* root, TreeNode* imin, TreeNode* imax) {
        if (!root) return true;
        if (imin && imin->val >= root->val) return false;
        if (imax && root->val >= imax->val) return false;
        return valid(root->left, imin, root) && valid(root->right, root, imax);
    }
};
