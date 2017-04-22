# -*- coding:utf-8 -*-


# Implement strStr().
#
#
# Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        lst = haystack.split(needle)
        if len(lst) == 1:
            return -1
        else:
            return len(lst[0])
