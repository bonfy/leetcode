// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: "3+2*2"
// Output: 7
//
//
// Example 2:
//
//
// Input: " 3/2 "
// Output: 1
//
// Example 3:
//
//
// Input: " 3+5 / 2 "
// Output: 5
//
//
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//


class Solution {
public:
    int calculate(string s) {
        long ans = 0, last = 0;
        char opr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                long tmp = 0;
                while (i < s.size() && isdigit(s[i])) {
                    tmp = tmp * 10 + s[i++] - '0';
                }
                --i;
                if (opr == '+') {
                    ans += tmp;
                    last = tmp;
                } else if (opr == '-') {
                    ans -= tmp;
                    last = -tmp;
                } else if (opr == '*') {
                    ans += last * (tmp - 1);
                    last *= tmp;
                } else if (opr == '/') {
                    ans = ans - last + last / tmp;
                    last /= tmp;
                } else if (opr == 0) {
                    ans = last = tmp;
                }
            } else {
                opr = s[i];
            }
        }
        return ans;
    }
};
