// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//
// If two nodes are in the same row and column, the order should be from left to right.
//
// Examples 1:
//
//
// Input: [3,9,20,null,null,15,7]
//
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7 
//
// Output:
//
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
//
//
// Examples 2:
//
//
// Input: [3,9,8,4,0,1,7]
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7 
//
// Output:
//
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
//
//
// Examples 3:
//
//
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
//
// Output:
//
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, vector<int>> vtk;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto [p, idx] = q.front();
            q.pop();
            vtk[idx].emplace_back(p->val);
            if (p->left) q.emplace(p->left, idx - 1);
            if (p->right) q.emplace(p->right, idx + 1);
        }
        for (auto& it: vtk) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};
