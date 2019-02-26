// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        int start = 0, maxlen = 1;
        for (int i = 0; i < s.size() && s.size() - i > (maxlen / 2); ) {
            int j = i, k = i;
            while (j + 1 < s.size() && s[j] == s[j + 1]) j++;
            i = j + 1;
            while (k > 0 && j + 1 < s.size() && s[k - 1] == s[j + 1]) {
                k--;
                j++;
            }
            int len = j - k + 1;
            if (len > maxlen) {
                maxlen = len;
                start = k;
            }
        }
        return s.substr(start, maxlen);
    }
};
