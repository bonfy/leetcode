// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols(n, 0), diag(2 * n - 1, 0), adiag(2 * n - 1, 0);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        function<void (vector<string>&, int)> solve = [&](vector<string>& board, int row) {
            if (row == n) {
                ans.emplace_back(board);
            } else {
                for (int i = 0; i < n; ++i) {
                    if (cols[i] || diag[row + i] || adiag[n - 1 - row + i]) continue;
                    cols[i] = diag[row + i] = adiag[n - 1 - row + i] = 1;
                    board[row][i] = 'Q';
                    solve(board, row + 1);
                    board[row][i] = '.';
                    cols[i] = diag[row + i] = adiag[n - 1 - row + i] = 0;
                }
            }
        };
        solve(board, 0);
        return ans;
    }
};
