// On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 0 <= y < N has a lamp.
//
// Initially, some number of lamps are on.  lamps[i] tells us the location of the i-th lamp that is on.  Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).
//
// For the i-th query queries[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0.
//
// After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).)
//
// Return an array of answers.  Each value answer[i] should be equal to the answer of the i-th query queries[i].
//
//  
//
// Example 1:
//
//
// Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
// Output: [1,0]
// Explanation: 
// Before performing the first query we have both lamps [0,0] and [4,4] on.
// The grid representing which cells are lit looks like this, where [0,0] is the top left corner, and [4,4] is the bottom right corner:
// 1 1 1 1 1
// 1 1 0 0 1
// 1 0 1 0 1
// 1 0 0 1 1
// 1 1 1 1 1
// Then the query at [1, 1] returns 1 because the cell is lit.  After this query, the lamp at [0, 0] turns off, and the grid now looks like this:
// 1 0 0 0 1
// 0 1 0 0 1
// 0 0 1 0 1
// 0 0 0 1 1
// 1 1 1 1 1
// Before performing the second query we have only the lamp [4,4] on.  Now the query at [1,0] returns 0, because the cell is no longer lit.
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^9
// 	0 <= lamps.length <= 20000
// 	0 <= queries.length <= 20000
// 	lamps[i].length == queries[i].length == 2
//
//


class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        unordered_map<int, int> row, col, diag, antidiag;
        unordered_map<int, unordered_map<int, int>> light;
        for (auto& l: lamps) {
            ++row[l[0]];
            ++col[l[1]];
            ++diag[l[0] + l[1]];
            ++antidiag[N - l[0] + l[1] - 1];
            light[l[0]][l[1]] = 1;
        }
        vector<int> ans;
        for (auto& q: queries) {
            if (row[q[0]] > 0 || col[q[1]] > 0 || diag[q[0] + q[1]] > 0 || antidiag[N - q[0] + q[1] - 1] > 0) {
                ans.emplace_back(1);
            } else {
                ans.emplace_back(0);
            }
            for (int i = 0; i < dir.size(); ++i) {
                if (light[q[0] + dir[i][0]][q[1] + dir[i][1]] == 1) {
                    light[q[0] + dir[i][0]][q[1] + dir[i][1]] = 0;
                    --row[q[0] + dir[i][0]];
                    --col[q[1] + dir[i][1]];
                    --diag[q[0] + dir[i][0] + q[1] + dir[i][1]];
                    --antidiag[N - (q[0] + dir[i][0]) + (q[1] + dir[i][1]) - 1];
                }
            }
        }
        return ans;
    }
};
