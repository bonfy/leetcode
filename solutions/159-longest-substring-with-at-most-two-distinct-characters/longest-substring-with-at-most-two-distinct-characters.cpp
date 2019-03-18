// Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
//
// Example 1:
//
//
// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
//
//
// Example 2:
//
//
// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.
//


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> counter(256, 0);
        int n = s.size(), slow = 0, ans = 0, diff = 0;
        for (int fast = 0; fast < n; fast++) {
            if (counter[s[fast]]++ == 0) diff++;
            while (diff > 2) {
                ans = max(ans, fast - slow);
                if (--counter[s[slow]] == 0) diff--;
                slow++;
            }
        }
        if (diff == 2) {
            ans = max(ans, n - slow);
        }
        if (diff < 2) {
            ans = n;
        }
        return ans;
    }
};
