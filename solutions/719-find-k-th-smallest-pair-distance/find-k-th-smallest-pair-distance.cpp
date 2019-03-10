// Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B. 
//
// Example 1:
//
// Input:
// nums = [1,3,1]
// k = 1
// Output: 0 
// Explanation:
// Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.
//
//
//
// Note:
//
// 2 <= len(nums) <= 10000.
// 0 <= nums[i] < 1000000.
// 1 <= k <= len(nums) * (len(nums) - 1) / 2.
//
//


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, h = 1000000;
        while (l < h) {
            int m = l + (h - l) /2;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= m) j++;
                cnt += j - i - 1;
            }
            if (cnt < k) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
};
