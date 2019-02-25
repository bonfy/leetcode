// Given a string, your task is to count how many palindromic substrings in this string.
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
// Example 1:
//
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//  
//
// Example 2:
//
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//  
//
// Note:
//
//
// 	The input string length won't exceed 1000.
//
//
//  
//


class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            ans += cntPal(s, i, i);
            ans += cntPal(s, i, i + 1);
        }
        return ans;
    }
    int cntPal(string s, int l, int h) {
        int ans = 0;
        while (0 <= l && h < s.size() && s[l] == s[h]) {
            ans++;
            l--;
            h++;
        }
        return ans;
    }
};
