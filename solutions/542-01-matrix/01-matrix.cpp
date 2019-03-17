//
// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
//
// The distance between two adjacent cells is 1.
//
// Example 1: 
// Input:
//
// 0 0 0
// 0 1 0
// 0 0 0
//
// Output:
//
// 0 0 0
// 0 1 0
// 0 0 0
//
//
//
// Example 2: 
// Input:
//
// 0 0 0
// 0 1 0
// 1 1 1
//
// Output:
//
// 0 0 0
// 0 1 0
// 1 2 1
//
//
//
// Note:
//
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.
//
//
//


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix);
        int m = ans.size(), n = ans[0].size();
        vector<int> dir{0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) continue;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                int dist = 0;
                while (!q.empty()) {
                    int qi = q.front().first;
                    int qj = q.front().second;
                    q.pop();
                    if (matrix[qi][qj] == 0) {
                        dist = abs(qi - i) + abs(qj - j);
                        break;
                    }
                    for (int k = 0; k < 4; k++) {
                        if (!valid(qi + dir[k], qj + dir[k + 1], m, n)) continue;
                        q.emplace(qi + dir[k], qj + dir[k + 1]);
                    }
                }
                ans[i][j] = dist;
            }
        }
        return ans;
    }
    inline bool valid(int x, int y, int m, int n) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
};
