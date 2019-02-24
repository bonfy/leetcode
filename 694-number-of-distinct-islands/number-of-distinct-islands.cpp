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
        unordered_set<string> islands;
        string path;
        function<void (int, int, char)> dfs = [&](int i, int j, char c) {
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) {
                path += 'f';
                return;
            }
            path += c;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dir[k], y = j + dir[k + 1];
                dfs(x, y, k + '1');
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    path.clear();
                    dfs(i, j, '0');
                    islands.emplace(path);
                }
            }
        }
        return islands.size();
    }
    vector<int> dir{0, -1, 0, 1, 0};
    
};
