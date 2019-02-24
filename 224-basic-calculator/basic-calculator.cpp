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
        // stack<long> stk;
        // int sym = 1;
        // long val = 0;
        // for (int i = 0; i < s.size(); ++i) {
        //     if (s[i] == ' ') continue;
        //     if (s[i] == '+') {
        //         sym = 1;
        //     } else if (s[i] == '-') {
        //         sym = -1;
        //     } else if (isdigit(s[i])) {
        //         int j = i;
        //         long num = 0;
        //         while (i < s.size() && isdigit(s[i])) {
        //             num *= 10;
        //             num += s[i] - '0';
        //             ++i;
        //         }
        //         --i;
        //         val += sym * num;
        //     } else if (s[i] == '(') {
        //         stk.emplace(val);
        //         val = 0;
        //         stk.emplace(sym);
        //         sym = 1;
        //     } else if (s[i] == ')') {
        //         val *= stk.top();
        //         stk.pop();
        //         val += stk.top();
        //         stk.pop();
        //     }
        // }
        // return val;
        vector<int> sym(2, 1);
        long val = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                long tmp = 0;
                while (i < s.size() && isdigit(s[i])) {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    ++i;
                }
                --i;
                val += sym.back() * tmp;
                sym.pop_back();
            } else if (s[i] == '+' || s[i] == '(') {
                sym.emplace_back(sym.back());
            } else if (s[i] == '-') {
                sym.emplace_back(-1 * sym.back());
            } else if (s[i] == ')') {
                sym.pop_back();
            }
        }
        return val;
    }
};
