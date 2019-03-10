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
class BSTIter {
public:
    stack<TreeNode*> stk;
    bool pos;
    BSTIter(TreeNode* r, bool dir): pos(dir) {
        setup(r);
    }
    int top() {
        return stk.top()->val;
    }
    int next() {
        auto p = stk.top();
        stk.pop();
        setup(!pos? p->left: p->right);
        return p->val;
    }
    void setup(TreeNode* r) {
        while (r) {
            stk.emplace(r);
            r = pos? r->left: r->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIter fwd(root, true);
        BSTIter bwd(root, false);
        while (fwd.top() < bwd.top()) {
            int v = fwd.top() + bwd.top();
            if (v == k) return true;
            if (v < k) fwd.next();
            else bwd.next();
        }
        return false;
        /*
        vector<int> nums;
        inorder(root, nums);
        return twosum(nums, k);
        */
    }
    void inorder(TreeNode* root, vector<int>& nums) {
        stack<TreeNode*> stk;
        auto p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            nums.emplace_back(p->val);
            p = p->right;
        }
    }
    bool twosum(vector<int>& nums, int k) {
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j];
            if (sum == k) return true;
            if (sum < k) i++;
            else j--;
        }
        return false;
    }
};
