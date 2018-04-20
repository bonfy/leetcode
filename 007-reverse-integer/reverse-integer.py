# -*- coding:utf-8 -*-


# Given a 32-bit signed integer, reverse digits of an integer.
#
# Example 1:
#
#
# Input: 123
# Output: 321
#
#
# Example 2:
#
#
# Input: -123
# Output: -321
#
#
# Example 3:
#
#
# Input: 120
# Output: 21
#
#
# Note:
# Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
#


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = list(str(abs(x)))
        l.reverse()
        rst = int(''.join(l))
        if rst > 2147483647:
            return 0
        else:
            return rst if x>=0 else rst * (-1)

            
