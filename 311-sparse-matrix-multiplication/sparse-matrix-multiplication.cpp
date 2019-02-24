// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
//


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = B.size();
        int k = B[0].size();
        vector<vector<int>> ans(m, vector<int>(k, 0));
        for (int i = 0; i < m; i++) {
            for (int y = 0; y < n; y++) {
                if (A[i][y] == 0) continue;
                for (int x = 0; x < k; x++) {
                    if (B[y][x] == 0) continue;
                    ans[i][x] += A[i][y] * B[y][x];
                }
            }
        }
        return ans;
    }
};
