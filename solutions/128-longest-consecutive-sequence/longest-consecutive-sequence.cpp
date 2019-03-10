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
        unordered_map<int, int> border;
        int imax = 0;
        for (int n: nums) {
            if (border[n] > 0) continue;
            int l = border[n - 1], r = border[n + 1];
            border[n] = 1 + border[n - 1] + border[n + 1];
            imax = max(border[n], imax);
            border[n - l] = border[n + r] = border[n];
        }
        return imax;
    }
};
