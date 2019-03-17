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
        function<void (string, int, int, pair<char, char>)> rm=[&](string str, int last_i, int last_j, pair<char, char> par) {
            for (int i = last_i, stk = 0; i < str.size(); ++i) {
                if (str[i] == par.first) ++stk;
                else if (str[i] == par.second) --stk;
                if (stk >= 0) continue;
                for (int j = last_j; j <= i; ++j) {
                    if (str[j] == par.second && (j == last_j || str[j - 1] != str[j])) {
                        rm(str.substr(0, j) + str.substr(j + 1), i, j, par);
                    }
                }
                return;
            }
            string rs(str.rbegin(), str.rend());
            if (par.first == '(') {
                rm(rs, 0, 0, {')', '('});
            } else {
                ans.emplace_back(rs);
            }
        };
        rm(s, 0, 0, {'(', ')'});
        return ans;
    }
};
