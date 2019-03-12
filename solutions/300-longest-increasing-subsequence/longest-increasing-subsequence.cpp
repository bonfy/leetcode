// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        int n = nums.size();
        int maxlen = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
        */
        vector<int> LIS;
        for (int n: nums) {
            fitLIS(LIS, n);
        }
        return LIS.size();
    }
    void fitLIS(vector<int>& nums, int n) {
        int l = 0, h = nums.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] < n) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if (l >= nums.size()) nums.emplace_back(n);
        else nums[l] = n;
    }
};
