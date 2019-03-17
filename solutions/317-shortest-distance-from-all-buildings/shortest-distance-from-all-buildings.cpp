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
        if (!n) return -1;
        vector<vector<int>> ngrid(grid);
        vector<vector<int>> total(m, vector<int>(n, 0));
        vector<int> dir{0, -1, 0, 1, 0};
        int canReach = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    vector<vector<int>> localdist(m, vector<int>(n, 0));
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int x = p.first + dir[i];
                            int y = p.second + dir[i + 1];
                            if (0 <= x && x < m && 0 <= y && y < n && ngrid[x][y] == canReach) {
                                ngrid[x][y]--;
                                localdist[x][y] = 1 + localdist[p.first][p.second];
                                total[x][y] += localdist[x][y];
                                q.emplace(x, y);
                            }
                        }
                    }
                    canReach--;
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ngrid[i][j] == canReach && total[i][j] < ans) {
                    ans = total[i][j];
                }
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};
