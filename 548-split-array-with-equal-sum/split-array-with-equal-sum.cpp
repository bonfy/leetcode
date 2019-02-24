//
// Given an array with n integers, you need to find if there are triplets  (i, j, k) which satisfies following conditions:
//
//  0 < i, i + 1 < j, j + 1 < k < n - 1 
//  Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal. 
//
// where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
//
//
// Example:
//
// Input: [1,2,1,2,1,2,1]
// Output: True
// Explanation:
// i = 1, j = 3, k = 5. 
// sum(0, i - 1) = sum(0, 0) = 1
// sum(i + 1, j - 1) = sum(2, 2) = 1
// sum(j + 1, k - 1) = sum(4, 4) = 1
// sum(k + 1, n - 1) = sum(6, 6) = 1
//
//
//
// Note:
//
//  1 <= n <= 2000. 
//  Elements in the given array will be in range [-1,000,000, 1,000,000]. 
//



class Solution {
public:
    bool splitArray(vector<int>& nums) {
        vector<int> sum(nums);
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] += sum[i - 1];
        }
        unordered_set<int> partsum;
        for (int j = 3; j + 3 < nums.size(); ++j) {
            if (j > 3 and nums[j] == 0 and nums[j - 1] == 0) continue;
            partsum.clear();
            for (int i = 1; i + 1 < j; ++i) {
                if (sum[i - 1] == sum[j - 1] - sum[i]) {
                    partsum.emplace(sum[i - 1]);
                }
            }
            for (int k = j + 2; k + 1 < nums.size(); ++k) {
                if (sum[k - 1] - sum[j] == sum.back() - sum[k] and partsum.count(sum.back() - sum[k])) return true; 
            }
        }
        return false;
    }
};
