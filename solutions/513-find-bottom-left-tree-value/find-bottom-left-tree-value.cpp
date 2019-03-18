//
// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        travel(root, 0);
        return v;
    }
private:
    int v;
    int d = -1;
    
    void travel(TreeNode* root, int dep) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr && dep > d) {
            v = root->val;
            d = dep;
            return;
        }
        travel(root->left, dep+1);
        travel(root->right, dep+1);
    }
};
