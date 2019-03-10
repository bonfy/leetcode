//
// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
//
//
// Example 1:
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
//
// Example 2:
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//
// Note:
// Your solution should run in O(log n) time and O(1) space.
//
//


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            if (m & 1) m--;
            if (nums[m] != nums[m + 1]) {
                h = m;
            } else {
                l = m + 2;
            }
        }
        return nums[l];
    }
};
