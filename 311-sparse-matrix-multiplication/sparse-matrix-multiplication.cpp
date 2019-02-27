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
        int k = A.size();
        int m = B.size();
        int n = B[0].size();
        vector<vector<int>> ans(k, vector<int>(n, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (!A[i][j]) continue;
                for (int k = 0; k < n; k++) {
                    if (!B[j][k]) continue;
                    ans[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return ans;
    }
};
