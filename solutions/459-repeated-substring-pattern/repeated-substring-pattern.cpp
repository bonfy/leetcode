// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
//
//  
//
// Example 1:
//
//
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
//
//
// Example 2:
//
//
// Input: "aba"
// Output: False
//
//
// Example 3:
//
//
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
//
//


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> next(n + 1, -1);
        int j = -1, i = 0;
        while (i < n) {
            if (j == -1 || s[j] == s[i]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        // last one is not zero, the last one represent the maximum len of reapted substr, (n - last) is the len of substr
        return next.back() && (next.back() % (n - next.back()) == 0);
    }
};
