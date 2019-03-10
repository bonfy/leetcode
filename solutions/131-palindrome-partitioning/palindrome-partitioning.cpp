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
            int l = idx, h = i;
            while (l < h && s[l] == s[h]) {
                l++;
                h--;
            }
            if (l >= h) {
                path.emplace_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, path, ans);
                path.pop_back();
            }
        }
    }
};
