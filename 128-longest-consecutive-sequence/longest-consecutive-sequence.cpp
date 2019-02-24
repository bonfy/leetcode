// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> bound;
        for (int n: nums) {
            if (bound[n]) continue;
            int left = bound[n - 1];
            int right = bound[n + 1];
            bound[n] = left + right + 1;
            bound[n - left] = bound[n + right] = bound[n];
            ans = max(ans, bound[n]);
        }
        return ans;
    }
};
