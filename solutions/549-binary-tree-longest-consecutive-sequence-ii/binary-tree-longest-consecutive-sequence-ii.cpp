// Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
//
// Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
//
// Example 1:
//
//
// Input:
//         1
//        / \
//       2   3
// Output: 2
// Explanation: The longest consecutive path is [1, 2] or [2, 1].
//
//
//  
//
// Example 2:
//
//
// Input:
//         2
//        / \
//       1   3
// Output: 3
// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
//
//
//  
//
// Note: All the values of tree nodes are in the range of [-1e7, 1e7].
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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    vector<int> dfs(TreeNode* root, int& ans) {
        if (!root) return {0, 0};
        vector<int> inc_dec{1, 1};
        if (root->left) {
            auto l = dfs(root->left, ans);
            if (root->val == root->left->val - 1) {
                inc_dec[0] = max(inc_dec[0], l[0] + 1);
            }
            if (root->val == root->left->val + 1) {
                inc_dec[1] = max(inc_dec[1], l[1] + 1);
            }
        }
        if (root->right) {
            auto r = dfs(root->right, ans);
            if (root->val == root->right->val - 1) {
                inc_dec[0] = max(inc_dec[0], r[0] + 1);
            }
            if (root->val == root->right->val + 1) {
                inc_dec[1] = max(inc_dec[1], r[1] + 1);
            }
        }
        ans = max(inc_dec[0] + inc_dec[1] - 1, ans);
        return inc_dec;
    }
};
