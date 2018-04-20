# -*- coding:utf-8 -*-


# Given two binary strings, return their sum (also a binary string).
#
# The input strings are both non-empty and contains only characters 1 or&nbsp;0.
#
# Example 1:
#
#
# Input: a = &quot;11&quot;, b = &quot;1&quot;
# Output: &quot;100&quot;
#
# Example 2:
#
#
# Input: a = &quot;1010&quot;, b = &quot;1011&quot;
# Output: &quot;10101&quot;
#


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        num = int(a, 2) + int(b,2)
        return bin(num)[2:]
