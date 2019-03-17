// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.
//
// Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".
//
// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.
//
//  
//
// Example 1:
//
//
// Input 1: a maze represented by a 2D array
//
// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0
//
// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (0, 1)
//
// Output: "lul"
//
// Explanation: There are two shortest ways for the ball to drop into the hole.
// The first way is left -> up -> left, represented by "lul".
// The second way is up -> left, represented by 'ul'.
// Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
//
//
//
// Example 2:
//
//
// Input 1: a maze represented by a 2D array
//
// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0
//
// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (3, 0)
//
// Output: "impossible"
//
// Explanation: The ball cannot reach the hole.
//
//
//
//  
//
// Note:
//
//
// 	There is only one ball and one hole in the maze.
// 	Both the ball and hole exist on an empty space, and they will not be at the same position initially.
// 	The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// 	The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.
//
//


class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        string ans("impossible");
        if (!m) return ans;
        int n = maze[0].size();
        if (maze[ball[0]][ball[1]] == 1 || maze[hole[0]][hole[1]] == 1) return ans;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[ball[0]][ball[1]] = 0;
        unordered_map<int, string> path;
        queue<pair<int, int>> q;
        q.emplace(ball[0], ball[1]);
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i, y = j;
                int len = dist[i][j];
                string tmp = path[i * n + j];
                while (0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0 && !(x == hole[0] && y == hole[1])) {
                    x += dir[k];
                    y += dir[k + 1];
                    len++;
                }
                if (!(x == hole[0] && y == hole[1])) {
                    x -= dir[k];
                    y -= dir[k + 1];
                    len--;
                }
                tmp += d[k];
                if (len < dist[x][y]) {
                    dist[x][y] = len;
                    path[x * n + y] = tmp;
                    if (!(x == hole[0] && y == hole[1])) q.emplace(x, y);
                } else if (len == dist[x][y] && tmp < path[x * n + y]) {
                    path[x * n + y] = tmp;
                    if (!(x == hole[0] && y == hole[1])) q.emplace(x, y);
                }
            }
            
        }
        return dist[hole[0]][hole[1]] == INT_MAX? ans: path[hole[0] * n + hole[1]];
    }
    vector<char> d{'l', 'u', 'r', 'd'};
    vector<int> dir{0, -1, 0, 1, 0};
};
