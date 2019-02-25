// Given two strings s and t, determine if they are both one edit distance apart.
//
// Note: 
//
// There are 3 possiblities to satisify one edit distance apart:
//
//
// 	Insert a character into s to get t
// 	Delete a character from s to get t
// 	Replace a character of s to get t
//
//
// Example 1:
//
//
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
//
//
// Example 2:
//
//
// Input: s = "cab", t = "ad"
// Output: false
// Explanation: We cannot get t from s by only one step.
//
// Example 3:
//
//
// Input: s = "1203", t = "1213"
// Output: true
// Explanation: We can replace '0' with '1' to get t.
//


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return isOneEditDistance(t, s);
        if (m - n > 1) return false;
        bool mismatch = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (m == n) {
                    t[i] = s[i];
                } else {
                    t.insert(i, 1, s[i]);
                } 
                mismatch = true;
                break;
            }
        }
        return (mismatch && s == t) || (!mismatch && m - n == 1);
    }
};
