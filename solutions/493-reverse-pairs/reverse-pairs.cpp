// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.
//
//


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size());
    }
    int mergesort(vector<int>& nums, int s, int e) {
        if (s + 1 >= e) return 0;
        int m = s + (e - s) / 2;
        int cnt = mergesort(nums, s, m) + mergesort(nums, m, e);
        int i = s, j = m;
        while (i < m) {
            while (j < e && nums[i] > 2.0 * nums[j]) {
                ++j;
            }
            cnt += j - m;
            ++i;
        }
        sort(nums.begin() + s, nums.begin() + e);
        return cnt;
    }
};
