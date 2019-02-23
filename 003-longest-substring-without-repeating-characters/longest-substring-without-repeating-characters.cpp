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
        vector<int> cnt(256, 0);
        int ans = 0;
        for (int slow = 0, fast = 0; fast < s.size(); ++fast) {
            ++cnt[s[fast]];
            while (cnt[s[fast]] > 1) {
                --cnt[s[slow++]];
            }
            ans = max(ans, fast - slow + 1);
        }
        return ans;
    }
};
