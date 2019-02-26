// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
//
//
// 	Each 0 marks an empty land which you can pass by freely.
// 	Each 1 marks a building which you cannot pass through.
// 	Each 2 marks an obstacle which you cannot pass through.
//
//
// Example:
//
//
// Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
//
// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
//
// Output: 7 
//
// Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
//              the point (1,2) is an ideal empty land to build a house, as the total 
//              travel distance of 3+3+1=7 is minimal. So return 7.
//
// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
//


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return -1;
        int n = grid[0].size();
        vector<vector<int>> ng(grid);
        vector<vector<int>> total(m, vector<int>(n, 0));
        int canReach = 0;
        vector<int> dir{0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    vector<vector<int>> dist(m, vector<int>(n, 0));
                    q.emplace(i, j);
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dir[i];
                            int ny = y + dir[i + 1];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && ng[nx][ny] == canReach) {
                                ng[nx][ny]--;
                                dist[nx][ny] = 1 + dist[x][y];
                                total[nx][ny] += dist[nx][ny];
                                q.emplace(nx, ny);
                            }
                        }
                    }
                    canReach--;
                }
            }
        }
        int d = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ng[i][j] == canReach && total[i][j]) {
                    d = min(total[i][j], d);
                }
            }
        }
        return d == INT_MAX? -1: d;
    }
};
