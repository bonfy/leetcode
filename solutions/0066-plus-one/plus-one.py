# -*- coding:utf-8 -*-


# Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
#
# The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
#
# You may assume the integer does not contain any leading zero, except the number 0 itself.
#
# Example 1:
#
#
# Input: [1,2,3]
# Output: [1,2,4]
# Explanation: The array represents the integer 123.
#
#
# Example 2:
#
#
# Input: [4,3,2,1]
# Output: [4,3,2,2]
# Explanation: The array represents the integer 4321.
#


class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        c = 1
        result = []
        for i in xrange(len(digits)-1, -1 , -1):
            t = c + digits[i]
            
            if t >= 10:
                result.append(t % 10)
                c = 1
            else:
                result.append(t)
                c = 0
        
        if c == 1:
            result.append(1)
        return result[::-1]
