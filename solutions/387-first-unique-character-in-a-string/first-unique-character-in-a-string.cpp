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
        if (s.empty()) return -1;
        vector<int> cnt(26, 0);
        for (int slow = 0, fast = 0; fast <= s.size(); ++fast) {
            if (fast == s.size()) return slow;
            ++cnt[s[fast] - 'a'];
            while (slow < s.size() && cnt[s[slow] - 'a'] > 1) {
                ++slow;
            }
            if (slow == s.size()) return -1;
        }
        return -1;
    }
};
