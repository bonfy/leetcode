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
        if (word.empty()) return true;
        int m = board.size();
        if (!m) return false;
        int n = board[0].size();
        if (!n) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, i, j, m, n, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> dir{0, 1, 0, -1, 0};
    bool search(vector<vector<char>>& board, int i, int j, int m, int n, string& word, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) return false;
        auto c = board[i][j];
        board[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            if (search(board, i + dir[k], j + dir[k + 1], m, n, word, idx + 1)) {
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
};
