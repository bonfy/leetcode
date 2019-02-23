// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
//
// Input: s = "anagram", t = "nagaram"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "rat", t = "car"
// Output: false
//
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
//


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        auto cnts = cnt(s);
        auto cntt = cnt(t);
        return cnts == cntt;
    }
    vector<int> cnt(string& s) {
        vector<int> ans(26, 0);
        for (char c: s) {
            ans[c - 'a']++;
        }
        return move(ans);
    }
};
