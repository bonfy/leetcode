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
        int n = nums.size(), maxs = INT_MIN;
        vector<int> sum(n + 1, 0), lpos(n, 0), rpos(n, n - k), ans(3);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = k + 1, lmax = sum[k] - sum[0]; i <= n - 2 * k; i++) {
            int tmp = sum[i] - sum[i - k];
            if (tmp > lmax) {
                lmax = tmp;
                lpos[i] = i - k;
            } else {
                lpos[i] = lpos[i - 1];
            }
        }
        for (int i = n - 2 * k - 1, rmax = sum[n] - sum[n - k]; i >= k; i--) {
            int tmp = sum[i + 2 * k] - sum[i + k];
            if (tmp > rmax) {
                rmax = tmp;
                rpos[i] = i + k;
            } else {
                rpos[i] = rpos[i + 1];
            }
        }
        for (int i = k; i <= n - 2 * k; i++) {
            int l = lpos[i], r = rpos[i];
            int tmp = sum[l + k] - sum[l] + sum[i + k] - sum[i] + sum[r + k] - sum[r];
            if (tmp > maxs) {
                maxs = tmp;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};
