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
        const int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0, l = 1, r = 1; i < n; ++i) {
            l *= nums[i];
            r *= nums[n - 1 - i];
            ans = max(ans, max(l, r));
            if (l == 0) l = 1;
            if (r == 0) r = 1;
        }
        return ans;
    }
};
