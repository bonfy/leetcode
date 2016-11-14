# -*- coding:utf-8 -*-


# Reverse digits of an integer.
#
#
# Example1: x =  123, return  321
# Example2: x = -123, return -321
#
#
# click to show spoilers.
#
# Have you thought about this?
#
# Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
#
# If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
#
# Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
#
# For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
#
#
# Update (2014-11-10):
# Test cases had been added to test the overflow behavior.


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

            
