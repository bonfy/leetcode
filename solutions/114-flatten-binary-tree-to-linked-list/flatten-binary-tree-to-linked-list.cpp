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
        // TreeNode* p = nullptr;
        // flt(root, p);
        auto now = root;
        while (now) {
            if (now->left) {
                auto prev = now->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = now->right;
                now->right = now->left;
                now->left = nullptr;
            }
            now = now->right;
        }
    }
    // void flt(TreeNode* p, TreeNode*& next) {
    //     if (!p) return;
    //     flt(p->right, next);
    //     flt(p->left, next);
    //     p->left = nullptr;
    //     p->right = next;
    //     next = p;
    // }
    // void flt2(TreeNode* p, TreeNode*& prev) {
    //     if (!p) return;
    //     auto l = p->left;
    //     auto r = p->right;
    //     if (prev) {
    //         prev->left = nullptr;
    //         prev->right = p;
    //     }
    //     prev = p;
    //     flt2(l, prev);
    //     flt2(r, prev);
    // }
};
