// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.
//
//


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int c = 24 * 60;
        vector<int> scale_time(n, 0);
        for (int i = 0; i < n; i++) {
            scale_time[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3));
        }
        sort(scale_time.begin(), scale_time.end());
        scale_time.emplace_back(scale_time[0] + c);
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, scale_time[i] - scale_time[i - 1]);
        }
        return ans;
    }
};
