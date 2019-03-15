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
    class Point {
        public:
        int x, y, l;
        Point(int x_, int y_, int l_) : x(x_), y(y_), l(l_) {}
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (!m) return -1;
        int n = maze[0].size();
        if (!n) return -1;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<int> dir{0, 1, 0, -1, 0};
        auto cmp = [](Point& a, Point& b){return a.l > b.l;};
        priority_queue<Point, vector<Point>, decltype(cmp)> pq(cmp);
        pq.emplace(start[0], start[1], 0);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (dist[p.x][p.y] <= p.l) continue;
            dist[p.x][p.y] = p.l;
            for (int i = 0; i < 4; i++) {
                int x = p.x, y = p.y, l = p.l;
                while (0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0) {
                    x += dir[i];
                    y += dir[i + 1];
                    l++;
                }
                // position before the wall
                x -= dir[i];
                y -= dir[i + 1];
                l--;
                pq.emplace(Point(x, y, l));
            }
        }
        int ans = dist[destination[0]][destination[1]];
        return ans == INT_MAX? -1: ans;
    }
};
