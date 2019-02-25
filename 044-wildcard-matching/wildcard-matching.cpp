// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
//
// Example 1:
//
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
//
// Example 2:
//
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
//
// Example 3:
//
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
//
// Example 4:
//
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
//
// Example 5:
//
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false
//
//


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0, last_i = -1, last_star = -1;
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                last_i = i;
                last_star = j++;
            } else if (last_star >= 0) {
                i = ++last_i;
                j = last_star + 1;
            } else {
                return false;
            }
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
