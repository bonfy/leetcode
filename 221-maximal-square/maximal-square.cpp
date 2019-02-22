// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
//
// Input: 
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
//


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        int len = 0;
        for (int i = 0; i < m; i++) {
            int prev = dp[0];
            dp[0] = matrix[i][0] == '1';
            len = max(len, dp[0]);
            for (int j = 1; j < n; j++) {
                int top = dp[j];
                if (matrix[i][j] == '1') {
                    dp[j] = 1 + min(dp[j - 1], min(top, prev));
                    len = max(len, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = top;
            }
        }
        return len * len;
    }
};
