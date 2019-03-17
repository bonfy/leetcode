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
        unordered_map<int, int> bounder;
        int len = 0;
        for (int& n: nums) {
            if (bounder[n] > 0) continue;
            int l = bounder[n - 1], r = bounder[n + 1];
            bounder[n] = bounder[n - l] = bounder[n + r] = (l + r + 1);
            len = max(len, bounder[n]);
        }
        return len;
    }
};
