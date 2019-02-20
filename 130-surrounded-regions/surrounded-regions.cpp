// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// Example:
//
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
// After running your function, the board should be:
//
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//
// Explanation:
//
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
//


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;
        for (int i = 0; i < m; i++) {
            check(i, 0, board);
            if (n > 1) check(i, n - 1, board);
        }
        for (int j = 0; j < n; j++) {
            check(0, j, board);
            if (m > 1) check(m - 1, j, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] == 'T'? 'O': 'X';
            }
        }
    }
    vector<int> dir{0, 1, 0, -1, 0};
    void check(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;
        board[i][j] = 'T';
        for (int k = 0; k < 4; k++) {
            check(i + dir[k], j + dir[k + 1], board);
        }
    }
};
