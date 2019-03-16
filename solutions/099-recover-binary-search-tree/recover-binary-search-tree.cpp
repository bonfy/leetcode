// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
//
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
//
//
// 	A solution using O(n) space is pretty straight forward.
// 	Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> stk;
        auto p = root;
        vector<TreeNode*> v;
        while (p || !stk.empty()) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            v.emplace_back(p);
            p = p->right;
        }
        int beg = 0, end = -1;
        int imax = v[0]->val, imin = v[v.size() - 1]->val;
        for (int i = 0; i < v.size(); i++) {
            imax = max(imax, v[i]->val);
            imin = min(imin, v[v.size() - 1 - i]->val);
            if (v[i]->val < imax) end = i;
            if (v[v.size() - 1 - i]->val > imin) beg = v.size() - 1 - i;
        }
        int vl = v[beg]->val;
        int vh = v[end]->val;
        v[end]->val = vl;
        v[beg]->val = vh;
    }
};
