// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
// Example 1:
//
//
// Input: "aacecaaa"
// Output: "aaacecaaa"
//
//
// Example 2:
//
//
// Input: "abcd"
// Output: "dcbabcd"


class Solution {
public:
    string shortestPalindrome(string s) {
        string pattern(s + "%" + string(s.rbegin(), s.rend()));
        int m = pattern.size();
        vector<int> next(m, -1);
        int j = -1;
        int i = 0;
        while (i < m - 1) {
            if (j == -1 || pattern[i] == pattern[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        string pre = s.substr(next.back() + 1);
        reverse(pre.begin(), pre.end());
        return pre + s;
    }
};
