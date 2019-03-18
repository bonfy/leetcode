// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
//
// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
//
//  
//
// Example 1:
//
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)
//
// Output: true
//
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
//
//
//
// Example 2:
//
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)
//
// Output: false
//
// Explanation: There is no way for the ball to stop at the destination.
//
//
//
//  
//
// Note:
//
//
// 	There is only one ball and one destination in the maze.
// 	Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// 	The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// 	The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
//
//


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (!m) return false;
        int n = maze[0].size();
        if (!n || maze[start[0]][start[1]] || maze[destination[0]][destination[1]]) return false;
        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        vector<vector<int>> inqueue(m, vector<int>(n));
        inqueue[start[0]][start[1]] = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first == destination[0] && p.second == destination[1]) return true;
            for (int k = 0; k < 4; k++) {
                int x = p.first, y = p.second;
                while (0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0) {
                    x += dir[k];
                    y += dir[k + 1];
                }
                x -= dir[k];
                y -= dir[k + 1];
                if (inqueue[x][y] == 0) {
                    q.emplace(x, y);
                    inqueue[x][y] = 1;
                }
            }
        }
        return false;
    }
    vector<int> dir{0, -1, 0, 1, 0};
};
