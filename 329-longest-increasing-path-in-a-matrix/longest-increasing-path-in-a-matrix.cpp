// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
// Example 1:
//
//
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
//
//
// Example 2:
//
//
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> mem(m, vector<int>(n, -1));
        function<int (int, int)> search = [&](int i, int j){
            if (mem[i][j] != -1) return mem[i][j];
            int step = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dir[k], y = j + dir[k + 1];
                if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j]) continue;
                step = max(step, search(x, y));
            }
            mem[i][j] = step + 1;
            return mem[i][j];
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(search(i, j), ans);
            }
        }
        return ans;
    }
    vector<int> dir{0, -1, 0, 1, 0};
};
