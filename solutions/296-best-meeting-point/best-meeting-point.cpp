// A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
//
// Example:
//
//
// Input: 
//
// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
//
// Output: 6 
//
// Explanation: Given three people living at (0,0), (0,4), and (2,2):
//              The point (0,2) is an ideal meeting point, as the total travel distance 
//              of 2+2+2=6 is minimal. So return 6.
//


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        vector<int> x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    x.emplace_back(i);
                }
            }
        }
        for (int j = 0; j < n; ++j) {    
            for (int i = 0; i < m; ++i) {
                if (grid[i][j]) {
                    y.emplace_back(j);
                }
            }
        }
        function <int (vector<int>&)> getMean = [](vector<int>& nums) {
            int i = 0, j = nums.size() - 1;
            int d = 0;
            while (i < j) {
                d += nums[j--] - nums[i++];
            }
            return d;
        };
        return getMean(x) + getMean(y);
    }
};
