//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (!n) return -1;
        vector<int> cnt(26, 0);
        int slow = 0;
        for (int fast = 0; fast < n; ++fast) {
            ++cnt[s[fast] - 'a'];
            while (slow < n && cnt[s[slow] - 'a'] > 1) ++slow;
            if (slow == n) return -1;
        }
        return slow;
    }
};
