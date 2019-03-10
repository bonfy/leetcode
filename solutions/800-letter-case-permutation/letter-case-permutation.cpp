// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
//
//
// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
// Input: S = "3z4"
// Output: ["3z4", "3Z4"]
//
// Input: S = "12345"
// Output: ["12345"]
//
//
// Note:
//
//
// 	S will be a string with length between 1 and 12.
// 	S will consist only of letters or digits.
//
//


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        //if (S.empty()) return {};
        vector<string> ans;
        ans.emplace_back("");
        for (char c: S) {
            if (isalpha(c)) {
                int n = ans.size();
                vector<string> tmp;
                for (int i = 0; i < n; i++) {
                    char c1 = tolower(c);
                    char c2 = toupper(c);
                    tmp.emplace_back(ans[i] + c1);
                    tmp.emplace_back(ans[i] + c2);
                }
                ans.swap(tmp);
            } else {
                for (int i = 0; i < ans.size(); i++) {
                    ans[i] += c;
                }
            }
        }
        return ans;
    }
};
