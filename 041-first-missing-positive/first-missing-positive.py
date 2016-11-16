# -*- coding:utf-8 -*-


# Given an unsorted integer array, find the first missing positive integer.
#
#
#
# For example,
# Given [1,2,0] return 3,
# and [3,4,-1,1] return 2.
#
#
#
# Your algorithm should run in O(n) time and uses constant space.


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if len(nums) == 0:
            return 1
        lst = range(1, length+2)
        for i in nums:
            if i > 0 and i < length+1 and i in lst:
                lst.remove(i)
        return lst[0]
