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
        if (!n) return 0;
        int lefttop = 0, maxedge = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if (matrix[i][j - 1] == '1') {
                    dp[j] = 1 + min(dp[j - 1], min(lefttop, dp[j]));
                    maxedge = max(maxedge, dp[j]);
                } else {
                    dp[j] = 0;
                }
                lefttop = tmp;
            }
        }
        return maxedge * maxedge;
    }
};
