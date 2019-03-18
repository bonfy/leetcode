// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example:
//
//
// Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
// Output: [1,1,2,3]
//
//
// Explanation:
//
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//
//
// 0 0 0
// 0 0 0
// 0 0 0
//
//
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
//
// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
//
// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
//
//
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
//
//
// Follow up:
//
// Can you do it in time complexity O(k log mn), where k is the length of the positions?
//


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> uf(m * n, -1);
        vector<int> ans;
        int island = 0;
        vector<int> dir{0, 1, 0, -1, 0};
        for (auto p: positions) {
            int x_ = p.first, y_ = p.second;
            int idx_ = x_ * n + y_;
            uf[idx_] = idx_;
            island++;
            for (int i = 0; i < 4; i++) {
                int x = x_ + dir[i], y = y_ + dir[i + 1];
                int idx = x * n + y;
                if (0 <= x && x < m && 0 <= y && y < n && uf[idx] != -1) {
                    int p_old = ufind(uf, idx_), p_new = ufind(uf, idx);
                    if (p_old != p_new) {
                        island--;
                        uf[p_old] = min(p_old, p_new);
                        uf[p_new] = uf[p_old];
                    }
                }
            }
            ans.emplace_back(island);
        }
        return ans;
    }
    int ufind(vector<int>& uf, int k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
