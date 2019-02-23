// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
//
//
// Example 2:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob1(nums, 0, nums.size() - 2), rob1(nums, 1, nums.size() - 1));
    }
    int rob1(vector<int>& nums, int l, int h) {
        int f_2 = 0, f_1 = nums[l];
        for (int i = l + 1; i <= h; ++i) {
            int cur = max(f_2 + nums[i], f_1);
            f_2 = f_1;
            f_1 = cur;
        }
        return f_1;
    }
};
