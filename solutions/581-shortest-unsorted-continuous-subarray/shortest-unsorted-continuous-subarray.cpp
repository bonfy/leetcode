// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=. 
//
//


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int beg = 0, end = -1;
        int imax = nums[0], imin = nums[n - 1];
        for (int i = 0; i < n; i++) {
            imax = max(imax, nums[i]);
            imin = min(imin, nums[n - 1 - i]);
            if (nums[i] < imax) end = i;
            if (imin < nums[n - 1 - i]) beg = n - 1 - i;
        }
        return end - beg + 1;
    }
};
