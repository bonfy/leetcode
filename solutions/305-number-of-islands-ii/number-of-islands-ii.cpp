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
        vector<int> ans;
        vector<int> dir{0, 1, 0, -1, 0};
        vector<int> uf(m * n, -1);
        int cnt = 0;
        for (auto p: positions) {
            int x = p.first, y = p.second;
            int idx = x * n + y;
            uf[idx] = idx;
            cnt++;
            for (int k = 0; k < 4; k++) {
                int xp = x + dir[k], yp = y + dir[k + 1];
                int idxp = xp * n + yp;
                if (valid(xp, yp, m, n) && uf[idxp] != -1) {
                    int p1 = ufind(uf, idx), p2 = ufind(uf, idxp);
                    if (p1 == p2) continue;
                    make_union(uf, p1, p2);
                    cnt--;
                }
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
    bool valid(int x, int y, int m, int n) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
    int ufind(vector<int>& uf, int k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
    void make_union(vector<int>& uf, int p1, int p2) {
        uf[p1] = min(p1, p2);
        uf[p2] = uf[p1];
    }
};
