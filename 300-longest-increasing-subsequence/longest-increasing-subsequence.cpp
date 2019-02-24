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
        vector<int> LIS;
        for (int n: nums) {
            find_pos(LIS, n);
        }
        return LIS.size();
    }
    void find_pos(vector<int>& LIS, int n) {
        int l = 0, h = LIS.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            if (LIS[m] < n) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if (l == LIS.size()) LIS.emplace_back(n);
        else {
            LIS[l] = n;
        }
    }
};
