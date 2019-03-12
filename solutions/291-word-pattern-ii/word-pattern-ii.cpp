// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
//
// Example 1:
//
//
// Input: pattern = "abab", str = "redblueredblue"
// Output: true
//
// Example 2:
//
//
// Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
// Output: true
//
// Example 3:
//
//
// Input: pattern = "aabb", str = "xyzabcxzyabc"
// Output: false
//
//
// Notes:
// You may assume both pattern and str contains only lowercase letters.
//


class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        m = pattern.size(), n = str.size();
        return backtrack(pattern, 0, str, 0);
    }
    bool backtrack(string& pattern, int i, string& str, int j) {
        if (i == m || j == n) {
            if (i == m && j == n) return true;
            return false;
        }
        for (int k = j; k < n; ++k) {
            string word = str.substr(j, k - j + 1);
            bool inserted = false;
            if (!c2s.count(pattern[i]) && !s2c.count(word)) {
                inserted = true;
                c2s[pattern[i]] = word;
                s2c[word] = pattern[i];
            } else if (!c2s.count(pattern[i]) || !s2c.count(word)) {
                continue;
            } else if (c2s[pattern[i]] != word || s2c[word] != pattern[i]) {
                continue;
            }
            if (backtrack(pattern, i + 1, str, k + 1)) return true;
            if (inserted) {
                c2s.erase(pattern[i]);
                s2c.erase(word);
            }
        }
        return false;
    }
    int m, n;
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
};
