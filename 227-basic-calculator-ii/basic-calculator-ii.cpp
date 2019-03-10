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
                long val = 0;
                while (i < s.size() && isdigit(s[i])) {
                    val = val * 10 + s[i++] - '0';
                }
                --i;
                if (opr == 0) {
                    ans = last = val;
                } else {
                    if (opr == '+') {
                        ans += val;
                        last = val;
                    } else if (opr == '-') {
                        ans -= val;
                        last = -val;
                    } else if (opr == '*') {
                        ans = ans - last + last * val;
                        last *= val;
                    } else if (opr == '/') {
                        ans = ans - last + last / val;
                        last /= val;
                    }
                    opr = 0;
                }
            } else {
                opr = s[i];
            }
        }
        return ans;
    }
};
