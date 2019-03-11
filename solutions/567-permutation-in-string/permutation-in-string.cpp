// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
//
// Example 1:
//
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
//
//
//
// Example 2:
//
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
//
//
//
// Note:
//
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
//
//


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        for (char& c: s1) {
            ++cnt[c - 'a'];
        }
        for (int slow = 0, fast = 0, counter = 0; fast < s2.size(); ++fast) {
            if (cnt[s2[fast] - 'a']-- > 0) {
                ++counter;
            }
            while (counter == s1.size()) {
                int len = fast - slow + 1;
                if (len == s1.size()) return true;
                if (++cnt[s2[slow++] - 'a'] > 0) {
                    --counter;
                }
            }
        }
        return false;
    }
};
