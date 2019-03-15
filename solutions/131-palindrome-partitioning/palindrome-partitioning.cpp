// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(s, 0, path, ans);
        return ans;
    }
    void backtrack(string s, int idx, vector<string>& path, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.emplace_back(path);
        }
        for (int i = idx; i < s.size(); i++) {
            auto cur = s.substr(idx, i - idx + 1);
            if (pal(cur)) {
                path.emplace_back(cur);
                backtrack(s, i + 1, path, ans);
                path.pop_back();
            }
        }
    }
    unordered_map<string, bool> mem;
    bool pal(string s) {
        if (mem.count(s)) return mem[s];
        for (int l = 0, h = s.size() - 1; l < h; l++, h--) {
            if (s[l] != s[h]) {
                mem[s] = false;
                return false;
            }
        }
        mem[s] = true;
        return true;
    }
};
