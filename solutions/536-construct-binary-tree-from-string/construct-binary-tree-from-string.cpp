// You need to construct a binary tree from a string consisting of parenthesis and integers. 
//
// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure. 
//
// You always start to construct the left child node of the parent first if it exists.
//
// Example:
//
// Input: "4(2(3)(1))(6(5))"
// Output: return the tree root node representing the following tree:
//
//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
//
//
//
// Note:
//
// There will only be '(',  ')',  '-' and  '0' ~ '9' in the input string.
// An empty tree is represented by "" instead of "()".
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
    TreeNode* str2tree(string s) {
        int pos = 0;
        return decode(s, pos);
    }
    TreeNode* decode(string& s, int& pos) {
        if (pos >= s.size()) return nullptr;
        int sym = 1;
        if (s[pos] == '-') {
            sym = -1;
            ++pos;
        }
        int val = 0;
        while (pos < s.size() && isdigit(s[pos])) {
            val *= 10;
            val += s[pos] - '0';
            ++pos;
        }
        TreeNode* root = new TreeNode(val * sym);
        if (pos < s.size() && s[pos] == '(') {
            root->left = decode(s, ++pos);
            ++pos;
        }
        if (pos < s.size() && s[pos] == '(') {
            root->right = decode(s, ++pos);
            ++pos;
        }
        return root;
    }
};
