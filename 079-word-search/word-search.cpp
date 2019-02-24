// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (!m) return false;
        int n = board[0].size();
        if (!n) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> dir{0, 1, 0, -1, 0};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || idx >= word.size() || board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        char c = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            if (dfs(board, word, i + dir[k], j + dir[k + 1], idx + 1)) {
                board[i][j] = c;
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
};
