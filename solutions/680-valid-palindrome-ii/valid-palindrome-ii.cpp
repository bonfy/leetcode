//
// Given a non-empty string s, you may delete at most one character.  Judge whether you can make it a palindrome.
//
//
// Example 1:
//
// Input: "aba"
// Output: True
//
//
//
// Example 2:
//
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
//
//
//
// Note:
//
// The string will only contain lowercase characters a-z.
// The maximum length of the string is 50000.
//
//


class Solution {
public:
    bool validPalindrome(string s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        function <bool (int, int)> pal = [&](int l, int h){
            while (l < h) {
                if (s[l] != s[h]) return false;
                ++l;
                --h;
            }
            return true;
        };
        while (i < j) {
            if (s[i] != s[j]) {
                return pal(i, j - 1) || pal(i + 1, j);
            }
            ++i;
            --j;
        }
        return true;
    }
};
