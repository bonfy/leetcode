//
// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//
// Find out how many ways to assign symbols to make sum of integers equal to target S.  
//
//
// Example 1:
//
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
//
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
//
// There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//
//
// Note:
//
// The length of the given array is positive and will not exceed 20. 
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.
//
//


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int cursum = accumulate(nums.begin(), nums.end(), 0);
        if ((cursum + S) & 1 || cursum < S) return 0;
        return count(nums, (cursum + S) / 2);
    }
    int count(vector<int>& nums, int s) {
        vector<int> cnt(s + 1, 0);
        cnt[0] = 1;
        for (int e: nums) {
            for (int t = s; t >= e; t--) {
                cnt[t] += cnt[t - e];
            }
        }
        return cnt[s];
    }
};
