// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
// Example:
//
//
// Input: 
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
//
// Output: ["eat","oath"]
//
//
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.


class Solution {
public:
    class Trie {
    public:
        string s;
        bool w;
        vector<Trie*> next;
        Trie():w(false) {
            next.resize(26, nullptr);
        }
    };
    void build(Trie* root, string& s) {
        auto p = root;
        for (int i = 0; i < s.size(); i++) {
            if (!p->next[s[i] - 'a']) {
                p->next[s[i] - 'a'] = new Trie();
            }
            p = p->next[s[i] - 'a'];
        }
        p->w = true;
        p->s = s;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (!m) return {};
        int n = board[0].size();
        if (!n) return {};
        Trie* root = new Trie();
        for (auto s: words) {
            build(root, s);
        }
        unordered_set<string> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root->next[board[i][j] - 'a'], ans);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
    vector<int> dir{0, 1, 0, -1, 0};
    void dfs(vector<vector<char>>& board, int x, int y, Trie* root, unordered_set<string>& ans) {
        if (!root) return;
        if (root->w) {
            ans.emplace(root->s);
        }
        char c = board[x][y];
        board[x][y] = '#';
        for (int k = 0; k < 4; k++) {
            int i = x + dir[k], j = y + dir[k + 1];
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] - 'a' >= 26 || board[i][j] - 'a' < 0) continue;
            dfs(board, i, j, root->next[board[i][j] - 'a'], ans);
        }
        board[x][y] = c;
    }
};
