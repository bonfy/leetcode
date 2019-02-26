// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
// Note: The input string may contain letters other than the parentheses ( and ).
//
// Example 1:
//
//
// Input: "()())()"
// Output: ["()()()", "(())()"]
//
//
// Example 2:
//
//
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
//
//
// Example 3:
//
//
// Input: ")("
// Output: [""]
//


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        rm(s, 0, 0, ans, {'(',')'});
        return ans;
    }
    void rm(string s, int last_i, int last_j, vector<string>& ans, vector<char> par) {
        for (int i = last_i, stk = 0; i < s.size(); i++) {
            if (s[i] == par[0]) stk++;
            if (s[i] == par[1]) stk--;
            if (stk >= 0) continue;
            for (int j = last_j; j <= i; j++) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
                    rm(s.substr(0, j) + s.substr(j + 1), i, j, ans, par);
                }
            }
            return;
        }
        string rs(s.rbegin(), s.rend());
        if (par[0] == '(') {
            rm(rs, 0, 0, ans, {')', '('});
        } else {
            ans.emplace_back(rs);
        }
    }
};
