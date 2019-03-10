// Given a string, determine if a permutation of the string could form a palindrome.
//
// Example 1:
//
//
// Input: "code"
// Output: false
//
// Example 2:
//
//
// Input: "aab"
// Output: true
//
// Example 3:
//
//
// Input: "carerac"
// Output: true
//


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnt;
        int single = 0;
        for (char& c: s) {
            if (++cnt[c] & 1) {
                ++single;
            } else {
                --single;
            }
        }
        return single < 2;
    }
};
