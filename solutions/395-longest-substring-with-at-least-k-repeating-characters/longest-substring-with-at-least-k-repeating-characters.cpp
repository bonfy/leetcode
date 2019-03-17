//
// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
//
//
// Example 1:
//
// Input:
// s = "aaabb", k = 3
//
// Output:
// 3
//
// The longest substring is "aaa", as 'a' is repeated 3 times.
//
//
//
// Example 2:
//
// Input:
// s = "ababbc", k = 2
//
// Output:
// 5
//
// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//
//


class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> dict(26, 0);
        for (char& c: s) {
            ++dict[c - 'a'];
        }
        int maxlen = 0;
        int i = 0;
        const int n = s.size();
        while (i + k - 1 < n) {
            while (i + k - 1 < n && dict[s[i] - 'a'] < k) ++i;
            vector<int> tmp_dict(26, 0);
            int len = 0;
            for (int j = i, useless = 0; j < n; ++j) {
                ++tmp_dict[s[j] - 'a'];
                if (tmp_dict[s[j] - 'a'] == 1) ++useless;
                if (tmp_dict[s[j] - 'a'] == k) --useless;
                if (useless == 0) len = j - i + 1;
            }
            maxlen = max(len, maxlen);
            i += max(1, len);
        }
        return maxlen;
    }
};
