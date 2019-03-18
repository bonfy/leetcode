// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
// Example:
//
//
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]
//
//


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int prev = lower;
        for (int k: nums) {
            if (prev < k) {
                ans.emplace_back(to_string(prev) + (prev < min(k - 1, upper)? "->" + to_string(min(k - 1, upper)): ""));
            }
            if (k >= upper) return ans;
            prev = k + 1;
        }
        if (prev <= upper) {
            ans.emplace_back(to_string(prev) + (prev < upper? "->" + to_string(upper): ""));
        }
        return ans;
    }
};
