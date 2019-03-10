// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pos;
        int ans = 0;
        pos.emplace(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                pos.emplace(i);
            } else {
                if (pos.top() >= 0 && s[pos.top()] == '(') {
                    pos.pop();
                    ans = max(ans, i - pos.top());
                } else {
                    pos.emplace(i);
                }
            }
        }
        return ans;
    }
};
