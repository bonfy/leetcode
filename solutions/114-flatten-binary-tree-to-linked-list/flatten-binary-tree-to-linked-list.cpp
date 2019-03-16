// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
//
// The flattened tree should look like:
//
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
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
    void flatten(TreeNode* root) {
        TreeNode* now = root;
        while (now) {
            if (now->left) {
                auto prev = now->left;
                while (prev && prev->right) {
                    prev = prev->right;
                }
                prev->right = now->right;
                now->right = now->left;
                now->left = nullptr;
            }
            now = now->right;
        }
    }
};
