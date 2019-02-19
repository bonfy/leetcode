// Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.
//
// Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree.  Also, a node is called a leaf if it has no children.
//
// In the following examples, the input tree is represented in flattened form row by row.
// The actual root tree given will be a TreeNode object.
//
// Example 1:
//
// Input:
// root = [1, 3, 2], k = 1
// Diagram of binary tree:
//           1
//          / \
//         3   2
//
// Output: 2 (or 3)
//
// Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
//
//
// Example 2:
//
// Input:
// root = [1], k = 1
// Output: 1
//
// Explanation: The nearest leaf node is the root node itself.
//
//
//
//
// Example 3:
//
// Input:
// root = [1,2,3,4,null,null,null,5,null,6], k = 2
// Diagram of binary tree:
//              1
//             / \
//            2   3
//           /
//          4
//         /
//        5
//       /
//      6
//
// Output: 3
// Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
//
//
//
// Note:
//
// root represents a binary tree with at least 1 node and at most 1000 nodes.
// Every node has a unique node.val in range [1, 1000].
// There exists some node in the given binary tree for which node.val == k.
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
    int findClosestLeaf(TreeNode* root, int k) {
        auto nodek = search(root, k);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.emplace(nodek);
        visited.emplace(nodek);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (!u->left && !u->right) return u->val;
            if (u->left && !visited.count(u->left)) {
                visited.emplace(u->left);
                q.emplace(u->left);
            }
                
            if (u->right && !visited.count(u->right)) {
                visited.emplace(u->right);
                q.emplace(u->right);
            }
            if (parent.count(u) && !visited.count(parent[u])) {
                visited.emplace(parent[u]);
                q.emplace(parent[u]);
            }
        }
        return -1;
    }
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* search(TreeNode* root, int k) {
        if (!root) return nullptr;
        if (root->val == k) return root;
        if (root->left) {
            parent[root->left] = root;
            auto l = search(root->left, k);
            if (l) return l;
        }
        if (root->right) {
            parent[root->right] = root;
            auto r = search(root->right, k);
            if (r) return r;
        }
        return nullptr;
    }
};
