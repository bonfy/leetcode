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
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, h = n - 1;
            while (l < h) {
                int nl = nums[l], nh = nums[h];
                int sum = nums[i] + nl + nh;
                if (sum == 0) {
                    ans.emplace_back(vector<int>{nums[i], nl, nh});
                    while (l < h && nums[l] == nl) l++;
                    while (l < h && nums[h] == nh) h--;
                } else if (sum < 0) {
                    l++;
                } else {
                    h--;
                }
            }
        }
        return ans;
    }
};
