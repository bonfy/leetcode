// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
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
class BST {
public:
    bool forward;
    stack<TreeNode*> stk;
    BST(TreeNode* root, bool dir): forward(dir) {
        setup(root);
    }
    void setup(TreeNode* root) {
        while (root) {
            stk.emplace(root);
            root = forward? root->left: root->right;
        }
    }
    bool hasnext() {return !stk.empty();}
    int next() {
        auto p = stk.top();
        stk.pop();
        forward? setup(p->right): setup(p->left);
        return p->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BST left = BST(root, true);
        BST right = BST(root, false);
        int l = left.next();
        int r = right.next();
        while (l < r) {
            int sum = l + r;
            if (sum == k) return true;
            if (sum < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};
