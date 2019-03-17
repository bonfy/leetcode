// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        int ans = 0;
        vector<int> uf(m * n, -1);
        function<int (int)> ufind = [&](int k){
            if (uf[k] != k) {
                uf[k] = ufind(uf[k]);
            }
            return uf[k];
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    int idx = i * n + j;
                    uf[idx] = idx;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k], y = j + dir[k + 1];
                        if (x < 0 || y < 0 || x >= m || y >= n || uf[x* n +y] == -1) continue;
                        int nid = ufind(x * n + y);
                        if (nid == idx) continue;
                        --ans;
                        uf[nid] = idx;
                    }
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '2';
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k], y = j + dir[k + 1];
            dfs(grid, x, y, m, n);
        }
    }
    vector<int> dir{0, -1, 0, 1, 0};
};
