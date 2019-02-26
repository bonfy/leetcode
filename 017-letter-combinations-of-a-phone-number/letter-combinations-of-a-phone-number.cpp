// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        ans.emplace_back("");
        for (char c: digits) {
            if (c < '0' || c > '9') continue;
            auto keys = dict[c - '0'];
            if (keys.empty()) continue;
            vector<string> tmp;
            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < keys.size(); j++) {
                    tmp.emplace_back(ans[i] + keys[j]);
                }
            }
            ans.swap(tmp);
        }
        return ans;
    }
};
