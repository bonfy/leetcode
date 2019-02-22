// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
//
// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//
// You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?
//
// Example 1:
//
//
// Input: [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
//
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
//
//
// Example 2:
//
//
// Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation:
//  0  1  2  3  4
// 24 23 22 21  5
// 12 13 14 15 16
// 11 17 18 19 20
// 10  9  8  7  6
//
// The final route is marked in bold.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
//
//
// Note:
//
//
// 	2 <= N <= 50.
// 	grid[i][j] is a permutation of [0, ..., N*N - 1].
//
//


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> uf(n * n);
        iota(uf.begin(), uf.end(), 0);
        vector<pair<int, int>> inv_map(n * n);
        int s = grid[0][0], e = grid[n - 1][n - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                inv_map[grid[i][j]] = make_pair(i, j);
            }
        }
        vector<int> dir{0, 1, 0, -1, 0};
        for (int t = 0; t <= n * n - 1; t++) {
            int x, y;
            tie(x, y) = inv_map[t];
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k], ny = y + dir[k + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (grid[nx][ny] < t) {
                    u(uf, grid[nx][ny], t);
                }
            }
            if (ufind(uf, s) == ufind(uf, e)) return t;
        }
        return -1;
    }
    int ufind(vector<int>& uz, int k) {
        if (uz[k] != k) {
            uz[k] = ufind(uz, uz[k]);
        }
        return uz[k];
    }
    void u(vector<int>& uf, int i, int j) {
        auto p = ufind(uf, i);
        auto q = ufind(uf, j);
        if (p > q) {
            uf[q] = p;
        } else {
            uf[p] = q;
        }
    }
};
