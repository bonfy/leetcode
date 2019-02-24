// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
//
//
// 	0 represents the obstacle can't be reached.
// 	1 represents the ground can be walked through.
// 	The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
//
//
//  
//
// You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).
//
// You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.
//
// You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.
//
// Example 1:
//
//
// Input: 
// [
//  [1,2,3],
//  [0,0,4],
//  [7,6,5]
// ]
// Output: 6
//
//
//  
//
// Example 2:
//
//
// Input: 
// [
//  [1,2,3],
//  [0,0,0],
//  [7,6,5]
// ]
// Output: -1
//
//
//  
//
// Example 3:
//
//
// Input: 
// [
//  [2,3,4],
//  [0,0,5],
//  [8,7,6]
// ]
// Output: 6
// Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
//
//
//  
//
// Hint: size of the given matrix will not exceed 50x50.
//


class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        if (!m) return 0;
        int n = forest[0].size();
        if (!n) return 0;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_pq(cmp);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1)
                min_pq.emplace(vector<int>{i, j, forest[i][j]});
            }
        }
        int ans = 0;
        vector<int> start(2, 0);
        while (!min_pq.empty()) {
            auto tree = min_pq.top();
            min_pq.pop();
            int step = find(forest, start, tree, m, n);
            if (step < 0) return -1;
            ans += step;
            
            start[0] = tree[0];
            start[1] = tree[1];
        }
        return ans;
    }
    vector<int> dir{0, 1, 0, -1, 0};
    int find(vector<vector<int>>& forest, vector<int> start, vector<int> tree, int m, int n) {
        int step = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[start[0]][start[1]] = 1;
        queue<vector<int>> q;
        q.emplace(start);
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto p = q.front();
                q.pop();
                if (p[0] == tree[0] && p[1] == tree[1]) return step;
                for (int k = 0; k < 4; k++) {
                    int x = p[0] + dir[k], y = p[1] + dir[k + 1];
                    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || forest[x][y] == 0) continue;
                    q.emplace(vector<int>{x, y});
                    visited[x][y] = 1;
                }
            }
            step++;
        }
        return -1;
    }
};
