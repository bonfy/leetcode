// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<int> dict(256, 0);
        int maxlen = 1;
        for (int slow = 0, fast = 0; fast < s.size(); fast++) {
            if (dict[s[fast]]++ > 0) {
                while (dict[s[fast]] > 1) {
                    dict[s[slow++]]--;
                }
            }
            maxlen = max(maxlen, fast - slow + 1);
        }
        return maxlen;
    }
};
