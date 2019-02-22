// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.
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
// Output: 12
//
// Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
//              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
// Output: -1
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
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (!m) return -1;
        int n = maze[0].size();
        if (maze[start[0]][start[1]] == 1 || maze[destination[0]][destination[1]] == 1) return -1;
        bool reach = false;
        queue<tuple<int, int, int>> q;
        q.emplace(start[0], start[1], 0);
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        while (q.size() && !reach) {
            for (int it = q.size(); it > 0; --it) {
                auto [i, j, w] = q.front();
                q.pop();
                if (dist[i][j] < w) continue;
                dist[i][j] = w;
                if (i == destination[0] and j == destination[1]) {
                    ans = min(ans, w);
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i, y = j, z = w;
                    while (0 <= x + dir[k] and x + dir[k] < m and 0 <= y + dir[k + 1] and y + dir[k + 1] < n and maze[x + dir[k]][y + dir[k + 1]] == 0) {
                        x += dir[k];
                        y += dir[k + 1];
                        z += 1;
                    }
                    if (0 <= x and x < m and 0 <= y and y < n and maze[x][y] == 0 && z < dist[x][y]) {
                        q.emplace(x, y, z);
                    }
                    
                }
            }
        }
        return ans == INT_MAX? -1: ans;
    }
    vector<int> dir{0, -1, 0, 1, 0};
};
