// Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
//
// Example 1:
//
//
// Input: [[1,1],[-1,1]]
// Output: true
//
//
//
// Example 2:
//
//
// Input: [[1,1],[-1,-1]]
// Output: false
//
//
// Follow up:
// Could you do better than O(n2) ?


class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n <= 1) return true;
        unordered_map<int, set<int>> y_x;
        int l = points[0].first;
        int h = l;
        for (auto p: points) {
            l = min(l, p.first);
            h = max(h, p.first);
            y_x[p.second].emplace(p.first);
        }
        double aim_x = l / 2.0 + h / 2.0;
        for (auto s: y_x) {
            for (auto left = s.second.begin(), right = s.second.end(); left != s.second.end(); left++) {
                double x = *left / 2.0 + *(--right) / 2.0;
                if (x != aim_x) return false;
                if (left == right) break;
            }
        }
        return true;
    }
};
