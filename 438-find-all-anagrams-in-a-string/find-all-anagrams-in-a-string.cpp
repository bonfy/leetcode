// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
//
//
//
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
//


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> dict(256, 0);
        for (int i = 0; i < p.size(); i++) {
            dict[p[i]]++;
        }
        vector<int> ans;
        for (int slow = 0, fast = 0, cnt = 0; fast < s.size(); fast++) {
            if (dict[s[fast]]-- > 0) {
                cnt++;
            }
            while (cnt == p.size()) {
                int len = fast - slow + 1;
                if (len == p.size()) {
                    ans.emplace_back(slow);
                }
                if (++dict[s[slow++]] > 0) {
                    cnt--;
                }
            }
        }
        return ans;
    }
};
