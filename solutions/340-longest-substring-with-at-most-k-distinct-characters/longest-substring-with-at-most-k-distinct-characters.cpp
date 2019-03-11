// Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
// Example 1:
//
//
//
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.
//
//
// Example 2:
//
//
// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.
//
//
//


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> counter(256, 0);
        int slow = 0, ans = 0, n = s.size(), diff = 0;
        for (int fast = 0; fast < n; fast++) {
            if (counter[s[fast]]++ == 0) diff++;
            while (diff > k) {
                ans = max(ans, fast - slow);
                if (--counter[s[slow]] == 0) diff--;
                slow++;
            }
        }
        if (diff == k) {
            ans = max(ans, n - slow);
        }
        if (diff < k) {
            ans = n;
        }
        return ans;
    }
};
