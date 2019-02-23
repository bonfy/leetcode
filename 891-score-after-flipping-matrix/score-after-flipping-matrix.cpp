// We have a two dimensional matrix A where each value is 0 or 1.
//
// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
//
// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//
// Return the highest possible score.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 20
// 	1 <= A[0].length <= 20
// 	A[i][j] is 0 or 1.
//
//
//


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        if (!m) return 0;
        int n = A[0].size();
        int cnt = (1 << (n - 1)) * m;
        for (int j = 1; j < n; j++) {
            int same = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][0] == A[i][j]) {
                    same++;
                }
            }
            cnt += (1 << (n - 1 - j)) * max(same, m - same);
        }
        return cnt;
    }
};
