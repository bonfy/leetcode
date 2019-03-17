// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
// Example:
//
// Input:
// [[0,0],[1,0],[2,0]]
//
// Output:
// 2
//
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
//
//


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int xi = points[i].first, yi = points[i].second;
            unordered_map<int, int> cnt;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int xj = points[j].first, yj = points[j].second;
                int dx = xi - xj, dy = yi - yj;
                int d = dx * dx + dy * dy;
                cnt[d]++;
            }
            for (auto it: cnt) {
                if (it.second > 1) {
                    // c (x, 2) * a(2, 2);
                    ans += (it.second) * (it.second - 1);
                }
            }
        }
        return ans;
    }
};
