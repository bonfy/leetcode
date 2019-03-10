// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
// Example 1:
//
//
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
//
// Example 2:
//
//
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
//
// Note:
// You may assume all input has valid answer.
//
// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        auto idx = [n](int i) { return (1 + 2 * i) % (n | 1);};
        int l = 0, i = 0, h = n - 1;
        while (i <= h) {
            if (nums[idx(i)] > mid) {
                swap(nums[idx(i++)], nums[idx(l++)]);
            } else if (nums[idx(i)] < mid) {
                swap(nums[idx(i)], nums[idx(h--)]);
            } else {
                i++;
            }
        }
    }
};
