# -*- coding:utf-8 -*-


# Write a function to find the longest common prefix string amongst an array of strings.


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]

        p = strs[0]
        idx, rest = 0, strs[1:]
        while len(p) > 0:
            while idx < len(rest) and len(p) <= len(rest[idx]) and p == rest[idx][:len(p)]:
                idx += 1
            if idx == len(rest):
                return p
            p = p[:-1]
        return ""

