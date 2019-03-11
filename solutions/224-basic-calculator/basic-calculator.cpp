// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// Example 1:
//
//
// Input: "1 + 1"
// Output: 2
//
//
// Example 2:
//
//
// Input: " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
//


class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        vector<int> sym(2, 1);
        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                int num = 0;
                while ('0' <= s[i] && s[i] <= '9' && i < s.size()) {
                    num = num * 10 + s[i++] - '0';
                }
                ans += sym.back() * num;
                sym.pop_back();
                i--;
            } else if (s[i] == ')') {
                sym.pop_back();
            } else if (s[i] != ' ') {
                sym.emplace_back(sym.back() * (s[i] == '-'? -1: 1));
            }
        }
        return ans;
    }
};