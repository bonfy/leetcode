// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
//
//
// Example 1:
//
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Example 2:
//
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Note:
// The length of the given binary array will not exceed 50,000.
//


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) nums[i] = -1;
        }
        int sum = 0, maxi = 0;
        unordered_map<int, int> sum_idx;
        sum_idx[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum_idx.count(sum)) {
                maxi = max(maxi, i - sum_idx[sum]);
            } else {
                sum_idx[sum] = i;
            }
        }
        return maxi;
    }
};
