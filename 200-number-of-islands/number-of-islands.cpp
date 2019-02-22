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
        if (!n) return 0;
        int cnt = 0;
        vector<int> dir{0, 1, 0, -1, 0};
        vector<int> uf(m * n, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int idx = i * n + j;
                    uf[idx] = idx;
                    cnt++;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dir[k], y = j + dir[k + 1];
                        int id = x * n + y;
                        if (valid(x, y, m, n) && uf[id] != -1) {
                            int p1 = ufind(uf, idx), p2 = ufind(uf, id);
                            if (p1 == p2) continue;
                            cnt--;
                            uf[p1] = min(p1, p2);
                            uf[p2] = uf[p1];
                        }
                    }
                }
            }
        }
        return cnt;
    }
    inline bool valid(int i, int j, int m, int n) {
        return (0 <= i && i < m && 0 <= j && j < n);
    }
    inline int ufind(vector<int>& uf, int k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
