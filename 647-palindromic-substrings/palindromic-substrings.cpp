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
        function<int (int, int)> cnt = [&](int l, int h) {
            int k = 0;
            while (0 <= l and h < s.size() and s[l] == s[h]) {
                ++k;
                --l;
                ++h;
            }
            return k;
        };
        for (int i = 0; i < s.size(); ++i) {
            ans += cnt(i, i);
            ans += cnt(i, i + 1);
        }
        return ans;
    }
};
