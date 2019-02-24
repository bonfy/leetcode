// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, h = nums.size() - 1;
            while (l < h) {
                int sum = nums[l] + nums[i] + nums[h];
                if (sum == 0) {
                    ans.emplace_back(vector<int>{nums[i], nums[l], nums[h]});
                    while (l < h && nums[l] == nums[l + 1]) l++;
                    while (l < h && nums[h] == nums[h - 1]) h--;
                    l++;
                    h--;
                } else if (sum > 0) {
                    h--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
