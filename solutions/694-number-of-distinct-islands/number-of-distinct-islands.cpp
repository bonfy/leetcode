// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)  You may assume all four edges of the grid are surrounded by water.
//
// Count the number of distinct islands.  An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
//
// Example 1:
//
// 11000
// 11000
// 00011
// 00011
//
// Given the above grid map, return 1.
//
//
// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.
// Notice that:
//
// 11
// 1
//
// and
//
//  1
// 11
//
// are considered different island shapes, because we do not consider reflection / rotation.
//
//
// Note:
// The length of each dimension in the given grid does not exceed 50.
//


class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        set<vector<vector<int>>> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<int>> newl;
                if (dfs(i, j, i, j, m, n, grid, newl)) {
                    islands.emplace(newl);
                }
            }
        }
        return islands.size();
    }
    vector<int> dir{0, -1, 0, 1, 0};
    bool dfs(int i, int j, int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& newl) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) {
            return false;
        }
        newl.emplace_back(x - i, y - j);
        grid[x][y] *= -1;
        for (int k = 0; k < 4; k++) {
            dfs(i, j, x + dir[k], y + dir[k + 1], m, n, grid, newl);
        }
        return true;
    }
};
