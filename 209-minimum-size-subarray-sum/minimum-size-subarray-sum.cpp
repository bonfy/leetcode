// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX;
        for (int slow = 0, fast = 0, sum = 0; fast < nums.size(); fast++) {
            sum += nums[fast];
            while (sum >= s) {
                minlen = min(minlen, fast - slow + 1);
                sum -= nums[slow++];
            }
        }
        return minlen == INT_MAX? 0: minlen;
    }
};
