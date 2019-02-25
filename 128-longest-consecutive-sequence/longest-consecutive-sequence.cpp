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
        unordered_map<int, int> bound;
        int len = 0;
        for (int n: nums) {
            if (bound[n]) continue;
            int left = bound[n - 1], right = bound[n + 1];
            bound[n] = left + right + 1;
            len = max(len, bound[n]);
            bound[n - left] = bound[n + right] = bound[n];
        }
        return len;
    }
};
