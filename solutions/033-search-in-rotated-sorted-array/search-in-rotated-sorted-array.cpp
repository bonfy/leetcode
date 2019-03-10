// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            if (target == nums[m]) {
                return m;
            }
            if (nums[lo] <= nums[m]) {
                if (nums[lo] <= target && target < nums[m]) {
                    hi = m - 1;
                } else {
                    lo = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[hi]) {
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }
        }
        return nums[lo] == target? lo: -1;
    }
};
