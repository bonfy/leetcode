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
        vector<int> uf(m * n, 0), cnt(m * n, 0);
        for (auto h: hits) {
            grid[h[0]][h[1]]--;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    addOneBrick(grid, uf, cnt, i, j, m, n, false);
                }
            }
        }
        vector<int> ans(hits.size());
        for (int k = hits.size() - 1; k >= 0; k--) {
            if (++grid[hits[k][0]][hits[k][1]] <= 0) {
                ans[k] = 0;
            } else {
                ans[k] = addOneBrick(grid, uf, cnt, hits[k][0], hits[k][1], m, n, true);
            }
        }
        return ans;
    }
    int addOneBrick(vector<vector<int>>& grid, vector<int>& uf, vector<int>& cnt, int i, int j, int m, int n, bool u4) {
        int idx = i * n + j;
        uf[idx] = idx;
        cnt[idx] = 1;
        int fixed = idx < n? 1: 0;
        if (i > 0 && grid[i - 1][j] == 1) fixed += unionf(uf, cnt, idx - n, idx, n);
        if (j > 0 && grid[i][j - 1] == 1) fixed += unionf(uf, cnt, idx - 1, idx, n);
        if (u4 && i + 1 < m && grid[i + 1][j] == 1) fixed += unionf(uf, cnt, idx + n, idx, n);
        if (u4 && j + 1 < n && grid[i][j + 1] == 1) fixed += unionf(uf, cnt, idx + 1, idx, n);
        return max(0, fixed - 1);
    }
    
    int unionf(vector<int>& uf, vector<int>& cnt, int k1, int k2, int n) {
        while (uf[k1] != k1) k1 = uf[k1];
        while (uf[k2] != k2) k2 = uf[k2];
        if (k1 == k2) return 0;
        if (k1 < n || k2 >= n) {
            cnt[k1] += cnt[k2];
            uf[k2] = k1;
            if (k1 < n && k2 >= n) return cnt[k2];
            return 0;
        }
        cnt[k2] += cnt[k1];
        uf[k1] = k2;
        return cnt[k1];
    }
};
