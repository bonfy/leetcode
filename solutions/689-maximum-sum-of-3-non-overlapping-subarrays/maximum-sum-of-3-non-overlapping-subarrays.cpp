//
// In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
//
//
// Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
//
//
// Return the result as a list of indices representing the starting position of each interval (0-indexed).  If there are multiple answers, return the lexicographically smallest one.
//
// Example:
//
// Input: [1,2,1,2,6,7,5,1], 2
// Output: [0, 3, 5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//
//
//
// Note:
// nums.length will be between 1 and 20000.
// nums[i] will be between 1 and 65535.
// k will be between 1 and floor(nums.length / 3).
//


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sum(n + 1, 0), posL(n, 0), posR(n, n - k);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int idx = k + 1, maxL = sum[k] - sum[0]; idx <= n - 2 * k; ++idx) {
            int cursum = sum[idx] - sum[idx - k];
            if (cursum > maxL) {
                maxL = cursum;
                posL[idx] = idx - k;
            } else {
                posL[idx] = posL[idx - 1];
            }
        }
        for (int idx = n - 2 * k - 1, maxR = sum[n] - sum[n - k]; idx >= k; --idx) {
            int cursum = sum[idx + 2 * k] - sum[idx + k];
            if (cursum > maxR) {
                maxR = cursum;
                posR[idx] = idx + k;
            } else {
                posR[idx] = posR[idx + 1];
            }
        }
        vector<int> ans;
        for (int idx = k, maxsum = 0; idx <= n - 2 * k; ++idx) {
            int l = posL[idx], r = posR[idx];
            int cursum = sum[l + k] - sum[l] + sum[idx + k] - sum[idx] + sum[r + k] - sum[r];
            if (cursum > maxsum) {
                maxsum = cursum;
                ans = {l, idx, r};
            }
        }
        return ans;
    }
};
