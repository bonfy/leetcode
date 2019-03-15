// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans{-1, -1};
        if (!n) return ans;
        int l = 0, h = n - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if (nums[l] != target) {
            return ans;
        }
        h = n - 1;
        ans[0] = l;
        while (l < h) {
            int m = l + (h - l) / 2 + 1;
            if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m;
            }
        }
        ans[1] = l;
        return ans;
    }
};
