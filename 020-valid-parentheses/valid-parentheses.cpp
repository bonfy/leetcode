// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
// Note that an empty string is also considered valid.
//
// Example 1:
//
//
// Input: "()"
// Output: true
//
//
// Example 2:
//
//
// Input: "()[]{}"
// Output: true
//
//
// Example 3:
//
//
// Input: "(]"
// Output: false
//
//
// Example 4:
//
//
// Input: "([)]"
// Output: false
//
//
// Example 5:
//
//
// Input: "{[]}"
// Output: true
//
//


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2) return false;
        unordered_map<char, char> mp{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (char c: s) {
            if (mp.count(c)) {
                if (!stk.empty() && mp[c] == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.emplace(c);
            }
        }
        return stk.empty();
    }
};
