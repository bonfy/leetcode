# -*- coding:utf-8 -*-


#
# Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
#
#
#
# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        s = sum(set(nums))*3
        for n in nums:
            s = s - n
        return s/2
