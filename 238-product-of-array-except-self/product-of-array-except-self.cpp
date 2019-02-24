// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
// Example:
//
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
//
//
// Note: Please solve it without division and in O(n).
//
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
//


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (!n) return {};
        vector<int> ans(n, 1);
        for (int i = 0, l = 1, r = 1; i < n; i++) {
            ans[i] *= l;
            l *= nums[i]; 
            ans[n - i - 1] *= r;
            r *= nums[n - i - 1];
        }
        return ans;
    }
};
