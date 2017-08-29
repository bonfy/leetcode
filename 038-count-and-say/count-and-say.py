# -*- coding:utf-8 -*-


# The count-and-say sequence is the sequence of integers with the first five terms as following:
#
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
#
#
#
# 1 is read off as &quot;one 1&quot; or 11.
# 11 is read off as &quot;two 1s&quot; or 21.
# 21 is read off as &quot;one 2, then one 1&quot; or 1211.
#
#
#
# Given an integer n, generate the nth term of the count-and-say sequence.
#
#
#
# Note: Each term of the sequence of integers will be represented as a string.
#
#
# Example 1:
#
# Input: 1
# Output: &quot;1&quot;
#
#
#
# Example 2:
#
# Input: 4
# Output: &quot;1211&quot;
#


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for i in range(n-1):
            count = 1
            temp = []
            for index in range(1, len(s)):
                if s[index] == s[index-1]:
                    count += 1
                else:
                    temp.append(str(count))
                    temp.append(s[index-1])
                    count = 1
            temp.append(str(count))
            temp.append(s[-1])
            s = ''.join(temp)
        return s
