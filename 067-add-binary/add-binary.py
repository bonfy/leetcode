# -*- coding:utf-8 -*-


#
# Given two binary strings, return their sum (also a binary string).
#
#
#
# For example,
# a = &quot;11&quot;
# b = &quot;1&quot;
# Return &quot;100&quot;.


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        num = int(a, 2) + int(b,2)
        return bin(num)[2:]
