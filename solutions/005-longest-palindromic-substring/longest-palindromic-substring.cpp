// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string preManache(string s) {
        string n_s = "!";
        for (auto c : s) {
            n_s += '#';
            n_s += c;
        }
        n_s += "#?";
        return n_s;
    }
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        string n_s = preManache(s);
        int size = n_s.size();
        vector<int> radium(size, 0);
        int right = 0, mid = 0, max_r = 0, p = 0, pivot = 0;
        for (int i = 1; i < size - 1; ++i) {
            if (i < right) {
                radium[i] = min(right - i, radium[2*mid - i]);
            }
            while (n_s[i - radium[i] - 1] == n_s[i + radium[i] + 1]) {
                ++radium[i];
            }
            if (i + radium[i] > right) {
                right = i + radium[i];
                mid = i;
            }
            if (radium[i] > max_r) {
                max_r = radium[i];
                pivot = i;
                p = (pivot - max_r - 1) / 2;
            }
        }
        return s.substr(p, max_r);
    }
};
