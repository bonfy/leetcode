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
        int n = s.size();
        vector<int> count(256, 0);
        int len = 0;
        for (int slow = 0, fast = 0, diff = 0; fast < n; fast++) {
            if (count[s[fast]]++ == 0) {
                diff++;
            }
            while (diff > 2) {
                if (--count[s[slow++]] == 0) {
                    diff--;
                }
            }
            len = max(len, fast - slow + 1);
        }
        return len;
    }
};
