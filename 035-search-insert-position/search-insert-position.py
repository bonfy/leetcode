# -*- coding:utf-8 -*-


# Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#
# You may assume no duplicates in the array.
#
#
# Here are few examples.
# [1,3,5,6], 5 &#8594; 2
# [1,3,5,6], 2 &#8594; 1
# [1,3,5,6], 7 &#8594; 4
# [1,3,5,6], 0 &#8594; 0


class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return 0
        
        for idx,val in enumerate(nums):
            if val >= target:
                return idx
        
        return len(nums)
