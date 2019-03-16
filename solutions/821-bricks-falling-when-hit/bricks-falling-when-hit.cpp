// We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.
//
// We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.
//
// Return an array representing the number of bricks that will drop after each erasure in sequence.
//
//
// Example 1:
// Input: 
// grid = [[1,0,0,0],[1,1,1,0]]
// hits = [[1,0]]
// Output: [2]
// Explanation: 
// If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
//
//
// Example 2:
// Input: 
// grid = [[1,0,0,0],[1,1,0,0]]
// hits = [[1,1],[1,0]]
// Output: [0,0]
// Explanation: 
// When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
//
//  
//
// Note:
//
//
// 	The number of rows and columns in the grid will be in the range [1, 200].
// 	The number of erasures will not exceed the area of the grid.
// 	It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
// 	An erasure may refer to a location with no brick - if it does, no bricks drop.
//
//


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        if (!m) return {};
        int n = grid[0].size();
        for (auto h: hits) {
            grid[h[0]][h[1]] = grid[h[0]][h[1]] == 1? 0: -1;
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                fix(grid, 0, j, m, n);
            }
        }
        vector<int> ans(hits.size(), 0);
        for (int t = hits.size() - 1; t >= 0; t--) {
            int i = hits[t][0], j = hits[t][1];
            if (grid[i][j] == 0) {
                bool findFixed = false;
                for (int k = 0; k < 4 && !findFixed; k++) {
                    int x = i + dir[k], y = j + dir[k + 1];
                    if (x >= m || y < 0 || y >= n) continue;
                    if (x < 0 || grid[x][y] == 2) findFixed = true;
                }
                if (findFixed) {
                    ans[t] = fix(grid, i, j, m, n) - 1;
                } else {
                    grid[i][j] = 1;
                }
            }
        }
        return ans;
    }
    vector<int> dir{0, -1, 0, 1, 0};
    int fix(vector<vector<int>>& grid, int i, int j, int m, int n) {
        int ans = 1;
        grid[i][j] = 2;
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
            ans += fix(grid, x, y, m, n);
        }
        return ans;
    }
};
