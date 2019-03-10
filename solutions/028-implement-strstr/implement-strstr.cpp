// Implement strStr().
//
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
//
//
// Input: haystack = "hello", needle = "ll"
// Output: 2
//
//
// Example 2:
//
//
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
//
//
// Clarification:
//
// What should we return when needle is an empty string? This is a great question to ask during an interview.
//
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> next(n, -1);
        int i = 0, j = -1;
        while (i < n - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        i = j = 0;
        for (; i < haystack.size() && j < n; i++) {
            while (j >= 0 && haystack[i] != needle[j]) {
                j = next[j];
            }
            j++;
        }
        if (j == n) return i - j;
        return -1;
    }
};
