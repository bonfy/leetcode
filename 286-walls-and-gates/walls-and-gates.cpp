// You are given a m x n 2D grid initialized with these three possible values.
//
//
// 	-1 - A wall or an obstacle.
// 	0 - A gate.
// 	INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//
//
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
// Example: 
//
// Given the 2D grid:
//
//
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
//
//
// After running your function, the 2D grid should be:
//
//
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
//
//


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<int> dir = {0, 1, 0 , -1, 0};
        int m = rooms.size();
        if (!m) return;
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            int x = idx.first, y = idx.second;
            for (int i = 0; i < 4; i++) {
                int newx = x + dir[i], newy = y + dir[i + 1];
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && rooms[newx][newy] == INT_MAX) {
                    rooms[newx][newy] = 1 + rooms[x][y];
                    q.emplace(newx, newy);
                }
            }
        }
    }
};
