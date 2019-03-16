// Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
//
// Example:
//
// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3
//
//
//
//
// Hint:
// The number of elements in the given matrix will not exceed 10,000.
//


class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if (!m) return 0;
        int n = M[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j]) {
                    dp[i][j][0] = i >= 1? dp[i - 1][j][0] + 1: 1;
                    ans = max(ans, dp[i][j][0]);
                    dp[i][j][1] = j >= 1? dp[i][j - 1][1] + 1: 1;
                    ans = max(ans, dp[i][j][1]);
                    dp[i][j][2] = i >= 1 && j >= 1? dp[i - 1][j - 1][2] + 1: 1;
                    ans = max(ans, dp[i][j][2]);
                    dp[i][j][3] = i >= 1 && j + 1 < n? dp[i - 1][j + 1][3] + 1: 1;
                    ans = max(ans, dp[i][j][3]);
                }
            }
        }
        return ans;
    }
};
