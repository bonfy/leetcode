// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
//
//  
//
// Example 1:
//
//
// Input: m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:
//
//
//
// Example 2:
//
//
// Input: m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:
//
//
//
//  
//
// Note:
//
//
// 	Once you move the ball out of boundary, you cannot move it back.
// 	The length and height of the grid is in range [1,50].
// 	N is in range [0,50].
//
//


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int t = 0; t < N; t++) {
            vector<int> prev(n, 0);
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    long path = 0;
                    path += x == 0? 1: prev[y];
                    path += y == 0? 1: prev[y - 1];
                    path += x == m - 1? 1: dp[x + 1][y];
                    path += y == n - 1? 1: dp[x][y + 1];
                    path %= 1000000007;
                    prev[y] = dp[x][y];
                    dp[x][y] = path;
                }
            }
        }
        return dp[i][j];
    }
};
