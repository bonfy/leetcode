// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> sorted;
        for (int& e: nums) {
            auto pos = lower_bound(sorted.begin(), sorted.end(), e);
            if (pos == sorted.end()) {
                sorted.emplace_back(e);
            } else {
                *pos = e;
            }
        }
        return sorted.size();
    }
};
