// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for (int i = 0, l = 1, r = 1; i < nums.size(); i++) {
            l *= nums[i];
            r *= nums[n - 1 - i];
            ans = max(ans, max(l, r));
            l = !l? 1: l;
            r = !r? 1: r;
        }
        return ans;
    }
};
