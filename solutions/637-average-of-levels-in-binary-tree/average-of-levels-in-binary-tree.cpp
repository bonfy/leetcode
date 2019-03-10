// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
//
// Example 1:
//
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
//
//
//
// Note:
//
// The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        double level = 0.0;
        int cnt = 0;
        vector<double> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        q.emplace(nullptr);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p) {
                level += p->val;
                cnt++;
                if (p->left) q.emplace(p->left);
                if (p->right) q.emplace(p->right);
            } else {
                ans.emplace_back(level / cnt);
                level = 0.0;
                cnt = 0;
                if (!q.empty()) q.emplace(p);
            }
        }
        return ans;
    }
};
