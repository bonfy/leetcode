# -*- coding:utf-8 -*-


# Given a binary array, find the maximum number of consecutive 1s in this array.
#
# Example 1:
#
# Input: [1,1,0,1,1,1]
# Output: 3
# Explanation: The first two digits or the last three digits are consecutive 1s.
#     The maximum number of consecutive 1s is 3.
#
#
#
# Note:
#
# The input array will only contain 0 and 1.
# The length of input array is a positive integer and will not exceed 10,000
#
#


class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = 0
        length = 0
        for idx, val in enumerate(nums):
            if val == 1:
                length += 1
            if val == 0:
                if length > m:
                    m = length
                length = 0
        
        if length > m:
            m = length
            
        return m
                
