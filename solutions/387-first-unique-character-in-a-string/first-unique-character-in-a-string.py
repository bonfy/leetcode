# -*- coding:utf-8 -*-


#
# Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
#
# Examples:
#
# s = "leetcode"
# return 0.
#
# s = "loveleetcode",
# return 2.
#
#
#
#
# Note: You may assume the string contain only lowercase letters.
#


class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = {}
        idx = {}
        for i in range(len(s)):
            if s[i] not in cnt:
                cnt[s[i]] = 1
            else:
                cnt[s[i]] += 1
            idx[s[i]] = i
        ans = len(s)
        for i in cnt:
            if cnt[i] == 1:
                ans = min(ans, idx[i])
        
        return ans if ans != len(s) else -1
