// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
//
// If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.
//
// Example 1:
//
//
// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation: 
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
//
//
//  
//
// Note:
//
//
// 	All the strings in the input will only contain lowercase letters.
// 	The length of S will be in the range [1, 20000].
// 	The length of T will be in the range [1, 100].
//
//
//  


class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            if (S[i] == T[0]) dp[0][i] = i;
        }
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (k != -1 && S[i] == T[j]) dp[j][i] = k;
                if (dp[j - 1][i] != -1) k = dp[j - 1][i];
            }
        }
        int start = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            int tmp_len = i - dp[n - 1][i] + 1;
            if (dp[n - 1][i] != -1 && tmp_len < len) {
                start = dp[n - 1][i];
                len = tmp_len;
            }
        }
        return start == -1? "": S.substr(start, len);
    }
};
