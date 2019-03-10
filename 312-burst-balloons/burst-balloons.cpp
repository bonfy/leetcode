// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
// Find the maximum coins you can collect by bursting the balloons wisely.
//
// Note:
//
//
// 	You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 	0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//
// Example:
//
//
// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        vector<vector<int>> rangeV(nums.size(), vector<int>(nums.size(), 0));
        
        for (int len = 1; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;
                int maxc = 0;
                for (int i = start; i <= end; i++) {
                    int coin = rangeV[start][i - 1] + rangeV[i + 1][end];
                    coin += nums[start - 1] * nums[i] * nums[end + 1];
                    maxc = max(maxc, coin);
                }
                rangeV[start][end] = maxc;
            }
        }
        return rangeV[1][n];
    }
};
