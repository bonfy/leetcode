// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
//
// Example 1:
//
//
//
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
//
//
// Output:
//
// 2
//
//
//
//
// Example 2:
//
//
//
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
//
//
// Output:
//
// 2
//
//
//
// Note:
// The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int l = longestUnivaluePath(root->left);
        int r = longestUnivaluePath(root->right);
        return max(max(l, r), num_connect(root->left, root->val) + num_connect(root->right, root->val));
    }
    int num_connect(TreeNode* root, int prev) {
        if (!root) return 0;
        if (root->val != prev) return 0;
        return 1 + max(num_connect(root->left, root->val), num_connect(root->right, root->val));
    }
};
