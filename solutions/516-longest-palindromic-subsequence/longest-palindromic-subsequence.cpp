//
// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//
// Example 1:
// Input: 
//
// "bbbab"
//
// Output: 
//
// 4
//
// One possible longest palindromic subsequence is "bbbb".
//
//
// Example 2:
// Input:
//
// "cbbd"
//
// Output:
//
// 2
//
// One possible longest palindromic subsequence is "bb".
//


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 1; len < n; len++) {
            for (int p = 0; p + len < n; p++) {
                if (s[p] == s[p + len]) {
                    dp[p][p + len] = 2 + dp[p + 1][p + len - 1];
                } else {
                    dp[p][p + len] = max(dp[p][p + len - 1], dp[p + 1][p + len]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
