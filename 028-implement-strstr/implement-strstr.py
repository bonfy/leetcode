# -*- coding:utf-8 -*-


# Implement strStr().
#
# Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#
# Example 1:
#
#
# Input: haystack = &quot;hello&quot;, needle = &quot;ll&quot;
# Output: 2
#
#
# Example 2:
#
#
# Input: haystack = &quot;aaaaa&quot;, needle = &quot;bba&quot;
# Output: -1
#
#
# Clarification:
#
# What should we return when needle is an empty string? This is a great question to ask during an interview.
#
# For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C&#39;s&nbsp;strstr() and Java&#39;s&nbsp;indexOf().
#


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
