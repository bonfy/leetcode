// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
//
// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//
// Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
//
// Examples:
//
//
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
//
//
//
// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
//
//
//
// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
//
//
//
// Input: board = [[3,2,4],[1,5,0]]
// Output: 14
//
//
// Note:
//
//
// 	board will be a 2 x 3 array as described above.
// 	board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
//
//


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target("123450");
        unordered_set<string> visited;
        string s;
        int m = board.size();
        if (!m) return 0;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s += to_string(board[i][j]);
            }
        }
        queue<string> q;
        q.emplace(s);
        visited.emplace(s);
        int ans = 0;
        vector<int> dir{1, -1, 3, -3};
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                s = q.front();
                q.pop();
                if (s == target) {return ans;}
                int idx = s.find('0');
                for (int k = 0; k < 4; k++) {
                    int next = idx + dir[k];
                    if (next < 0 || next > 5 || (idx == 2 && next == 3) || (idx == 3 && next == 2)) continue;
                    string ss(s);
                    char t = ss[next];
                    ss[next] = '0';
                    ss[idx] = t;
                    if (!visited.count(ss)) {
                        q.emplace(ss);
                        visited.emplace(ss);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
